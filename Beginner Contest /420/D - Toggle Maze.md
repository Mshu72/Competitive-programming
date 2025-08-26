## 解答例
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    // S と G の位置を探す
    int sx = -1, sy = -1, gx = -1, gy = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == 'S') { sx = i; sy = j; }
            if (a[i][j] == 'G') { gx = i; gy = j; }
        }
    }

    const int INF = 1e9;
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // d[c][x][y]: 状態 c (0/1) で (x,y) に到達する最短距離
    vector<vector<vector<int>>> d(
        2, vector<vector<int>>(h, vector<int>(w, INF))
    );

    struct Node { int c, x, y; };
    queue<Node> q;

    // スタートは状態 c=0 から
    q.push({0, sx, sy});
    d[0][sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int c = cur.c, x = cur.x, y = cur.y;

        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k], yy = y + dy[k];

            // 盤面外・壁は不可
            if (!(0 <= xx && xx < h && 0 <= yy && yy < w)) continue;
            if (a[xx][yy] == '#') continue;

            // 状態による通行制限
            if (c == 0 && a[xx][yy] == 'x') continue;
            if (c == 1 && a[xx][yy] == 'o') continue;

            // '?' で状態トグル
            int cc = c ^ (a[xx][yy] == '?');

            // その (座標, 状態) が未訪問なら距離更新
            if (d[cc][xx][yy] == INF) {
                d[cc][xx][yy] = d[c][x][y] + 1;
                q.push({cc, xx, yy});
            }
        }
    }

    int ans = min(d[0][gx][gy], d[1][gx][gy]);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
```

## 解説

# 問題のざっくり

* `h×w` のマップがあり、`S`（スタート）から `G`（ゴール）まで最短手数で移動したい。
* 上下左右に1マスずつ動ける。`#` は壁で通れない。
* さらに「状態 c（0/1）」というフラグを持っていて、

  * c=0 のときは `x` を通れない
  * c=1 のときは `o` を通れない
  * `?` のマスに入ると **c がトグル**（0↔1）される
* 最短手数（移動回数）を求める。到達不可能なら -1。

---

# 入力を読む

```cpp
int h, w;
cin >> h >> w;
vector<string> a(h);
for (int i = 0; i < h; ++i) cin >> a[i];
```

* 高さ `h`、幅 `w` を読み、続けてマップ（文字列）を `a` に入れます。
* `a[i][j]` が (i 行 j 列) の文字になります。

---

# S と G を探す

```cpp
int sx=-1, sy=-1, gx=-1, gy=-1;
for (int i = 0; i < h; ++i)
  for (int j = 0; j < w; ++j) {
    if (a[i][j] == 'S') { sx=i; sy=j; }
    if (a[i][j] == 'G') { gx=i; gy=j; }
  }
```

* マップ全体を走査して、S と G の座標を見つけます。

---

# 定数・方向ベクトル・距離配列

```cpp
const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
```

* `INF` は「未訪問」を表す大きな数。
* `dx, dy` は上下左右に動くための差分。

```cpp
// d[c][x][y] : 状態 c (0/1) で (x,y) に到達する最短距離
vector<vector<vector<int>>> d(
  2, vector<vector<int>>(h, vector<int>(w, INF))
);
```

* 距離を **状態ごと** に持ちます（配列を2枚持つイメージ）。
* これで「同じマスでも c=0/1 で別の最短距離」を管理できます。

> ※ ここは型推論（CTAD）に頼らず、明示型で書くと初学者にもわかりやすいです。

---

# BFS の初期化

```cpp
struct Node { int c, x, y; };
queue<Node> q;
q.push({0, sx, sy});
d[0][sx][sy] = 0;
```

* キューに「状態 c=0、スタート座標」を入れて開始。
* `d[0][S] = 0`（スタート地点の距離は 0 手）。

---

# BFS 本体

```cpp
while (!q.empty()) {
    auto [c, x, y] = q.front(); q.pop();
    for (int k = 0; k < 4; ++k) {
        int xx = x + dx[k], yy = y + dy[k];
        ...
```

* キューから 1 つ取り出し、そのマスから上下左右へ広げます。

## 盤面チェックと通行可否

```cpp
// 盤面外 or 壁 はNG
if (!(0 <= xx && xx < h && 0 <= yy && yy < w)) continue;
if (a[xx][yy] == '#') continue;

// 状態cによる禁止マス
if (c == 0 && a[xx][yy] == 'x') continue;
if (c == 1 && a[xx][yy] == 'o') continue;
```

* 「盤面内か」「`#` でないか」
* 「c=0 のとき `x` は不可」「c=1 のとき `o` は不可」

## '?' で状態トグル

```cpp
int cc = c ^ (a[xx][yy] == '?');
```

* `a[xx][yy]` が `?` なら `(a[xx][yy] == '?')` は 1 なので `c ^ 1` で反転（XOR）。
* `?` 以外なら `0` なので `c ^ 0` → 変化なし。

## 未訪問なら距離更新＆プッシュ

```cpp
if (d[cc][xx][yy] != INF) continue; // 既訪問
d[cc][xx][yy] = d[c][x][y] + 1;      // 1 手進む
q.push({cc, xx, yy});
```

* 同じ（座標, 状態）の組み合わせに初めて到達したら、距離を更新しキューへ。

---

# 答えを出す

```cpp
int ans = min(d[0][gx][gy], d[1][gx][gy]);
cout << (ans == INF ? -1 : ans) << '\n';
```

* ゴール `(gx,gy)` に **c=0 / c=1 どちらの状態で着いても良い**ので、2つの最小を取ります。
* どちらも `INF`（未到達）なら `-1`。

---

# 計算量

* BFS はマス数×状態数ぶんだけ各マスを 1 回ずつ処理するので **O(2·h·w)**（実質 O(h·w)）。
* メモリは `d[2][h][w]` 相当。

---

# その他

* **なぜ状態が必要？**
  `?` に入った回数の偶奇で「通れる記号」が変わるから。同じマスでも “状態違い” で再訪する価値がある。
* **なぜ BFS？**
  1 手ずつ均等コストで進む最短路は BFS がぴったり（Dijkstra より軽い）。
* **`^` の意味は？**
  XOR（排他的論理和）。`c` を 0/1 で反転させるのに便利（`c = 1 - c` と同じ効果）。


