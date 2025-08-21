## 解答
```C++
#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    static constexpr int SIGMA = 26;
    vector<array<int, SIGMA>> next;
    vector<int> last;   // bitmask of matched patterns ending at the node
    vector<int> link;   // failure links

    AhoCorasick() {
        next.push_back({});
        next[0].fill(-1);
        last.push_back(0);
    }

    void add(const string &s, int id) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (next[v][c] == -1) {
                next[v][c] = (int)next.size();
                next.push_back({});
                next.back().fill(-1);
                last.push_back(0);
            }
            v = next[v][c];
        }
        last[v] |= (1 << id);
    }

    void build() {
        link.assign(next.size(), 0);
        queue<int> q;
        // initialize root transitions
        for (int c = 0; c < SIGMA; ++c) {
            int u = next[0][c];
            if (u == -1) next[0][c] = 0;
            else {
                link[u] = 0;
                q.push(u);
            }
        }
        // BFS
        while (!q.empty()) {
            int v = q.front(); q.pop();
            last[v] |= last[link[v]];
            for (int c = 0; c < SIGMA; ++c) {
                int u = next[v][c];
                if (u == -1) next[v][c] = next[link[v]][c];
                else {
                    link[u] = next[link[v]][c];
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 998244353;

    int N, L;
    if (!(cin >> N >> L)) return 0;
    AhoCorasick AC;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        AC.add(s, i);
    }
    AC.build();

    int m = (int)AC.next.size();
    int FULL = (1 << N) - 1;

    vector<vector<int>> dp(1 << N, vector<int>(m, 0));
    dp[0][0] = 1;

    for (int step = 0; step < L; ++step) {
        vector<vector<int>> ndp(1 << N, vector<int>(m, 0));
        for (int bit = 0; bit <= FULL; ++bit) {
            const auto &row = dp[bit];
            for (int v = 0; v < m; ++v) {
                int cur = row[v];
                if (!cur) continue;
                for (int c = 0; c < 26; ++c) {
                    int to = AC.next[v][c];
                    int nbit = bit | AC.last[to];
                    int &ref = ndp[nbit][to];
                    ref += cur;
                    if (ref >= MOD) ref -= MOD;
                }
            }
        }
        dp.swap(ndp);
    }

    long long ans = 0;
    for (int v = 0; v < m; ++v) {
        ans += dp[FULL][v];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans % MOD << '\n';
    return 0;
}
```

---

## 解説

## 全体の目的

* **与えられたN個の単語**をすべて含むような長さLの文字列（アルファベット小文字からなる文字列）の数を求める問題です。
* ただし、答えは大きくなるので **mod = 998244353** で割った余りを計算します。

---

## 処理の流れ

### 1. Aho-Corasick オートマトン（AC自動機）の構築

これは「複数の単語が文字列に出現するか」を効率的に判定するための仕組みです。

* **Trie木**を作る
  → 単語を一文字ずつ辿って登録し、単語の終わりに「ここでこの単語が終わる」という印を付けます。

* **失敗リンク**を作る
  → あるノードで次の文字が見つからなかった場合、どこに戻ればよいかを示すリンクです。これにより、全ての単語を同時に検索できるようになります。

* **last配列**
  → そのノードに来たとき「どの単語がマッチしているか」をビットマスクで保持します。
  例：`last[v] = 0b101` なら、単語ID 0と2がここで出現したという意味。

---

### 2. 動的計画法（DP）の準備

* 状態は次の2つで表されます：

  1. **bit**: どの単語をすでに含んだか（N個の単語についてビットマスクで管理）。
     例：`bit = 0b011` なら「単語0と1は含んだが、2はまだ」という状態。
  2. **v**: Aho-Corasickオートマトン上で現在いるノード（状態）。

* `dp[bit][v]` = 「これまでに長さ○○の文字列を作って、bitの単語を含んでいて、ACオートマトンの状態vにいる文字列の数」。

* 初期状態: `dp[0][0] = 1`（まだ何も選んでいない、ルートにいる）。

---

### 3. 文字を1つずつ追加して遷移

長さLまで繰り返します。

* ある状態 `(bit, v)` から次の文字 `c` を追加すると：

  * `to = AC.next[v][c]` で次の状態に移動。
  * `nbit = bit | AC.last[to]` で「新しくマッチした単語」を追加。
  * `ndp[nbit][to] += dp[bit][v]` と更新。

* これを長さLまで繰り返すと、すべての文字列をカウントできます。

---

### 4. 答えの出力

* 最後に欲しいのは「すべての単語を含む文字列の数」なので、
  → `bit = (1<<N)-1` （全ての単語を含んだ状態）の dp を合計します。
* それを `mod` で割って出力。

---

## まとめ（初心者向けイメージ）

* **Aho-Corasick**は「複数の単語が出現するかどうかをまとめて管理できる辞書みたいなもの」。
* **DP**は「文字列を1文字ずつ伸ばしながら、その時点で 'どの単語を含んだか' を管理して数える方法」。
* 最後に「全部の単語を含んだ場合」だけ答えに加えます。


