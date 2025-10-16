## 解答例
```cpp
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  // T回のテストケースがある
  int T;
  cin >> T;
  while (T--)
  {
    
    int N,M,K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector G(N, vector<int>());
    
    rep(_,M){
      int u,v;
      cin >> u >> v;
      u--;v--;
      G[u].push_back(v);
    }
    

    vector<bool> dp(N);
    rep(i,N) dp[i]= S[i] =='A';
    rep(step,K) {
      {
        //Bob
        vector<bool> ep(N, true);
        rep(i,N) for (int j:G[i]) if(!dp[j]) ep[i] = false;
        dp = move(ep);
      }
      {
        //Alice
        vector<bool> ep(N, false);
        rep(i,N) for (int j:G[i]) if(dp[j]) ep[i] = true;
        dp = move(ep);
      }
    }

    cout << (dp[0] ? "Alice" : "Bob") << '\n';

  }
```
## 解説

## コードの目的（概要）

* 複数のテストケースを処理する。
* 各テストでは：

  * **N個の頂点**を持つ**有向グラフ**が与えられる。
  * 各頂点には `'A'` または `'B'` の状態が与えられる（文字列 `S`）。
  * **Alice と Bob が交互に動くゲーム**を K ターン行い、最終的に頂点0の状態が `'A'` 側か `'B'` 側かを出力する。

---

## ステップバイステップ解説

### テストケースの数を読む

```cpp
int T;
cin >> T;
while (T--) {
```

* `T` 回のテストケースを処理。
* `T--` はループごとに1減らして0になるまで続く。

---

### グラフと初期状態の入力

```cpp
int N, M, K;
cin >> N >> M >> K;
string S;
cint >> S;
```


* `N` : 頂点数
* `M` : 辺の数
* `K` : 繰り返し回数（ゲームのターン数）
* `S` : 各頂点の初期状態（'A' = Alice有利, 'B' = Bob有利）

---

### グラフを構築

```cpp
vector G(N, vector<int>());
rep(_, M) {
  int u, v;
  cin >> u >> v;
  u--; v--;
  G[u].push_back(v);
}
```

* `G` は **隣接リスト形式の有向グラフ**
  例：`G[u]` は「頂点 u から行ける頂点の一覧」。
* 1-indexed 入力を 0-indexed に変換。

---

### 状態DPの初期化

```cpp
vector<bool> dp(N);
rep(i, N) dp[i] = S[i] == 'A';
```

* `dp[i]` = 現在、頂点 i が **Alice 側（A）なら true**, **Bob 側（B）なら false**

---

### Kターン繰り返す

```cpp
rep(step, K) {
  {
    // Bobフェーズ
    vector<bool> ep(N, true);
    rep(i, N) for (int j : G[i]) if (!dp[j]) ep[i] = false;
    dp = move(ep);
  }
  {
    // Aliceフェーズ
    vector<bool> ep(N, true);
    rep(i, N) for (int j : G[i]) if (dp[j]) ep[i] = true;
    dp = move(ep);
  }
}
```

---

### Bobフェーズ（ANDロジック）

```cpp
vector<bool> ep(N, true);
rep(i, N)
  for (int j : G[i])
    if (!dp[j]) ep[i] = false;
```

* 頂点 i のすべての遷移先 j が **true(A)** なら i も true。
* 1つでも false(B) の遷移先があるなら、i は false。
* 「**Bobは慎重に動く（全ての選択肢で有利でないとtrueにしない）**」＝ANDロジック。

---

### Aliceフェーズ（ORロジック）

```cpp
vector<bool> ep(N, true);   // ←ここバグ。falseで初期化すべき
rep(i, N)
  for (int j : G[i])
    if (dp[j]) ep[i] = true;
```

* 頂点 i のどれか1つでも遷移先 j が true なら i も true。
* 1つもなければ false。
* 「**Aliceは積極的に動く（どれか一手で有利になればtrue）**」＝ORロジック。


---

### 結果出力

```cpp
cout << (dp[0] ? "Alice" : "Bob") << '\n';
```

* 最終的に `dp[0]` が true なら `"Alice"`, false なら `"Bob"` を出力。

---

##  処理の全体像（概念的に）

1. 初期状態 `S` から始めて、

   * Bob手番では：**すべての行き先がAならA、1つでもBならB**
   * Alice手番では：**1つでも行き先がAならA、全部BならB**
2. これを K 回繰り返す。
3. 最終的な頂点0の状態を出力。

---

## 計算量

* 1ステップで全頂点と全辺を走査 → O(N + M)
* Kターン繰り返し → O(K × (N + M))
* これを Tテストケース分。




  
}
