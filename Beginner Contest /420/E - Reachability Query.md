# 解答例
```cpp
#include<bits/stdc++.h>
#include<atcoder/dsu>

using namespace std;
using namespace atcoder;

int main() {
  int n,q;
  cin >> n >> q;
  dsu d(n+1);
  vector<int> c(n+1, 0);
  vector<int> s(n+1, 0);

  while(q--){
    int typ;
    cin >> typ;
    if(typ ==1){
      int u,v;
      cin >> u >> v;
      u = d.leader(u);
      v = d.leader(u);
      if(u!=v){
        d.merge(u,v);
        int w=d.leader(u);
        s[w] = s[u] + s[v];
        s[u^v^w]=0;
      }
    }
    else if (typ ==2){
      int u;
      cin >> u;
      s[d.leader(u)]-=c[u];
      c[u]^=1;
      s[d.leader(u)]+=c[u];
    }
    else{
      int u;
      cin >> u;
      if(s[d.leader(u)]){cout << "Yes\n";}
      else{cout << "No\n";}
    }
  }
  return 0;
}
```

---

# 解説
このコードは **Union-Find**（DSU）を使って「頂点が属するグループ（連結成分）」を管理しつつ、各グループ内に **フラグが1の頂点が何個あるか** を数え、問い合わせに答えるプログラムです。

---

## 登場人物（配列や構造）

* `dsu d(n+1);`
  AtCoder Library の **Union-Find**。要素は `0..n`（実際に使うのは 1..n）。
  主な操作：

  * `d.merge(u,v)` … `u` と `v` の属する集合を結合
  * `d.leader(x)` … `x` を含む集合の代表（根）を返す

* `vector<int> c(n+1, 0);`
  各頂点 `u` の **フラグ**（0 or 1）。はじめは全て 0。

* `vector<int> s(n+1, 0);`
  **各グループの代表（根）に対してだけ**、そのグループ内のフラグ1の**個数の合計**を入れておく箱。
  代表以外の添字は 0（または使わない）に保つ方針。

> つまり「`c[u]` は各頂点の0/1」「`s[root]` は rootグループの 1 の総数」。

---

## クエリの種類と処理

ループで `q` 回クエリを処理します。

### 1) `typ == 1`：結合（Union）

```cpp
int u, v; cin >> u >> v;
u = d.leader(u);      // uの根
v = d.leader(v);      // vの根
if (u != v) {
  d.merge(u, v);      // 2つの集合を結合
  int w = d.leader(u);// 結合後の新しい根（uかvのどちらか）
  s[w] = s[u] + s[v]; // グループ内の「1の個数」を合算して新しい根に載せる
  s[u ^ v ^ w] = 0;   // もう片方の旧根の箱は0にする（後述のXORトリック）
}
```

* まず `u` と `v` の**根**を取ります（根同士を結合するため）。
* `merge` 後の根 `w` は **`u` か `v` のどちらか**になります（ACLの仕様）。
* `s[w]` に **両成分の 1 の合計**を載せ、**もう片方の旧根**の `s` は 0 にします。
* `s[u ^ v ^ w] = 0;` は「`u, v, w` の中で `w` ではない方の旧根」を特定する**XORトリック**です。
  （`u^v^w` は、`u` と `v` と `w` のうち重複している値が相殺され、残った値＝もう一方の旧根になります）

> 初学者向けには次のように書き換えると分かりやすいです：
>
> ```cpp
> int ru = d.leader(u), rv = d.leader(v);
> if (ru != rv) {
>   int w = d.merge(ru, rv);       // 返り値wをサポートする書き方の方が直感的
>   s[w] = s[ru] + s[rv];
>   if (w != ru) s[ru] = 0;
>   if (w != rv) s[rv] = 0;
> }
> ```

### 2) `typ == 2`：頂点 `u` のフラグをトグル（0↔1）

```cpp
int u; cin >> u;
s[d.leader(u)] -= c[u]; // まず「現在のc[u]ぶん」をグループ合計から引く
c[u] ^= 1;              // c[u] を 0↔1 反転
s[d.leader(u)] += c[u]; // 反転後の値ぶんをグループ合計に足す
```

* `c[u]` を反転するだけでは、**グループ合計** `s[root]` がずれるので、
  反映のために **引いてから足す** を行っています。
* `d.leader(u)` はトグルの前後で変わらない（結合は発生しない）ので、同じ root のはずです。

### 3) `typ == 3`：問い合わせ（Yes/No）

```cpp
int u; cin >> u;
if (s[d.leader(u)]) cout << "Yes\n";
else                 cout << "No\n";
```

* `u` が属するグループの `s[root]` が **0でなければ**（＝1が1つ以上あれば）「Yes」。
  そうでなければ「No」。

---

## 何をしているプログラム？

* **Union-Find** でグループ（連結成分）を管理。
* 各頂点のフラグ `c[u]` を **0/1で切り替え**できる。
* 各グループの代表 `root` に「そのグループ内の 1 の総数」を `s[root]` に持たせる。
* クエリで

  * グループを結合：合計 `s` を足して、片方の旧根の `s` は 0 に
  * 頂点のフラグを反転：属するグループの `s` を増減
  * 問い合わせ：属するグループに 1 があるか？

---

## 計算量

* `leader` / `merge` は **ほぼ O(1)**（アッカーマン逆関数：実質定数時間）
* 各クエリあたり定数個の操作なので、全体で **O(Q α(N))** 程度

---

## つまずきポイントとコツ

* **`s` は「根の添字」にだけ意味がある**：結合後は新しい根に合計を載せ、**もう片方は0**にするのを忘れない（コードではXORトリックでやっている）。
* **1-index前提**なので `dsu d(n+1)` とし、`1..n` をそのまま使っている（`0` は未使用）。
* わかりやすさ優先なら、上のように `ru, rv, w` を使い分けて代入するのがオススメ（XORは慣れないと読みにくい）。

---

## 参考：読みやすく書き直した版

```cpp
#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    dsu d(n + 1);                 // 1..n を使う
    vector<int> c(n + 1, 0);      // 各頂点のフラグ
    vector<long long> s(n + 1, 0);// 各根の「1の総数」（long longにしても良い）

    while (q--) {
        int typ;
        cin >> typ;

        if (typ == 1) {
            int u, v; cin >> u >> v;
            int ru = d.leader(u), rv = d.leader(v);
            if (ru != rv) {
                int w = d.merge(ru, rv);  // 新しい根（ru または rv）
                s[w] = s[ru] + s[rv];     // 合計を新根へ
                if (w != ru) s[ru] = 0;   // 旧根は0クリア
                if (w != rv) s[rv] = 0;
            }
        } else if (typ == 2) {
            int u; cin >> u;
            int r = d.leader(u);
            s[r] -= c[u];   // 反映をいったん引く
            c[u] ^= 1;      // 0↔1 反転
            s[r] += c[u];   // 新しい値を足す
        } else {
            int u; cin >> u;
            cout << (s[d.leader(u)] ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
```

