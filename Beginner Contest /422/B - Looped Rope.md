## 解答
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int i=0;i<H;i++)cin >> S[i];

  for (int i=0;i<H;i++){
    const string& row= S[i];
    for (int j=0;j<W;j++){
      if(row[j] != '#')continue;

      int d=0;
      if (i > 0     && S[i-1][j] == '#') ++d;
      if (i + 1 < H && S[i+1][j] == '#') ++d;
      if (j > 0     && row[j-1] == '#') ++d;
      if (j + 1 < W && row[j+1] == '#') ++d;
      
      if (d != 2 && d != 4) { cout << "No\n"; return 0; }
    }
  }
  
  cout << "Yes\n";
  return 0;

}
```
## 解説
このコードは「各 `'#'` の上下左右にある `'#'` の個数 `d` が **2 または 4** かどうかを全マスでチェックし、1つでも外れたら `No`、全部満たせば `Yes`」という判定になっています。境界条件も `i>0`/`i+1<H`/`j>0`/`j+1<W` で正しく保護されています。

# ここがポイント

* `const string& row = S[i];` は、その行の参照を取って **左/右** のチェックを少しだけ高速＆読みやすくしています（`row[j±1]`）。
  上下は `S[i±1][j]` としていてOK。
* 計算量は **O(HW)**。最大でも 400 マス程度なら十分高速。
* `'#'` が1つもない場合は「全ての `'#'` が条件を満たす」が空真となるため **Yes** を出します（仕様としてそれで良ければOK）。

# 改善の余地（好み）

同じパターンを4回書かずに、**方向配列**と**ラムダ**でまとめると保守しやすくなります（将来8方向にしたい時など）。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];

    // 「単純な輪だけ」を要求するなら true（d==2のみ許可）
    // 「交差点もOKな一筆書き可能」を要求するなら false（d==2 or 4）
    constexpr bool STRICT_SIMPLE_CYCLE = false;

    auto inb = [&](int r, int c) { return 0 <= r && r < H && 0 <= c && c < W; };
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = { 0, 0,-1, 1};

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] != '#') continue;

            int d = 0;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k], nj = j + dc[k];
                if (inb(ni, nj) && S[ni][nj] == '#') ++d;
            }

            if (STRICT_SIMPLE_CYCLE) {
                if (d != 2) { cout << "No\n"; return 0; }
            } else {
                if (d != 2 && d != 4) { cout << "No\n"; return 0; }
            }
        }
    }
    cout << "Yes\n";
    return 0;
}

```
処理解説
```cpp
  auto inb [&](int r, int c){retun 0 <=r && r < H && 0 <= c && c<W;};
  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};
```
この3行は「グリッド上で上下左右のマスを見るための“道具セット”」です。

### 1) `inb`（in bounds = 範囲内か？）

```cpp
auto inb = [&](int r, int c){ return 0 <= r && r < H && 0 <= c && c < W; };
```

* **ラムダ式**（その場で作る小さな関数）。`inb(r, c)` と呼べる“関数っぽい変数”になります。
* `auto` は「ラムダの型を自動推論してね」という意味。
* `[&]` は **キャプチャ**。外側の変数 `H` と `W` を**参照**で使う、という指定です（`H`/`W` の最新値を見ます）。
* 中身は **範囲チェック**：行 `r` が `0..H-1`、列 `c` が `0..W-1` なら `true` を返します。
  つまり「(r,c) が盤面の内側？」を一行で判定。

> 例：`if (inb(i+1, j)) { ... }` で「下マスが存在するなら…」の意味になります。

---

### 2) `dr` / `dc`（方向ベクトル）

```cpp
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = { 0, 0,-1, 1};
```

* `dr` は **行方向の変化量**、`dc` は **列方向の変化量**。
* 同じ添字を組にして使うと **上下左右**が表せます：

  * `k=0` → 上（`(-1, 0)`）
  * `k=1` → 下（`( +1, 0)`）
  * `k=2` → 左（`( 0, -1)`）
  * `k=3` → 右（`( 0, +1)`）
* これで「上下左右」を **同じコードでループ処理**できます。

> 使い方例：
>
> ```cpp
> int d = 0;
> for (int k = 0; k < 4; ++k) {
>     int ni = i + dr[k], nj = j + dc[k];
>     if (inb(ni, nj) && S[ni][nj] == '#') ++d;
> }
> ```

---

### まとめ

* `inb` は「その座標が盤面内か？」を返す関数。
* `dr`/`dc` は「上下左右への移動量」を並べた配列。
* 組み合わせると、**境界チェック込みで隣接4方向をスマートに走査**できます。
  斜めも見たいなら、`dr/dc` を8方向に増やすだけで拡張できます。
