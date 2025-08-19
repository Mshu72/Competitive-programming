## 解答
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  int X = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
  int Y = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
  int ans = (max(X,Y) + 1) / 2;

  cout << ans << '\n'; 
  return 0;

}
```

## 解説

- 入力で **n 個の点 (x[i], y[i])** をもらいます。
- x 座標の最小値・最大値を取り、その差 **X = max(x) − min(x)** を計算。
- y 座標でも同様に差 **Y = max(y) − min(y)** を計算。
- そして **ans = ⌈max(X, Y) / 2⌉** を出力しています（`(max(X,Y)+1)/2` は整数演算での切り上げ）。

## 直感的な意味

- 点集合を囲む**最小の軸平行の長方形**（バウンディングボックス）を考えると、幅が X、高さが Y です。
- 「チェビシェフ距離（キングの移動距離：1 手で上下左右斜めに 1 マス動ける）」で見ると、中心から半径 r の正方形（辺 2r）が“到達できる範囲”になります。
- 点を全部おさめるには、**半径 r ≥ max(X, Y)/2** が必要十分。
    
    中心をバウンディングボックスの中心に置けば入ります。
    
- 半径は整数なので **r = ⌈max(X, Y)/2⌉** —— これが `ans` です。

> たとえば、X=5, Y=4 なら max=5、半径は切り上げで 3 が最小。
> 
> 
> 半径 2 だと正方形の一辺が 4 なので入り切りません。
> 

## 計算量

- `max_element` と `min_element` を 2 回ずつ使っており、どれも **O(n)**。
    
    全体でも **O(n)**、メモリも **O(n)**（ベクトルを保持するため）です。
    

## 小さな改善（より実戦的）

- 座標が大きい可能性に備えて **`long long`** を使う。
- ベクトルに保存せず、読みながら最小・最大を更新すれば **O(1) メモリ** にできます。

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long minx = LLONG_MAX, maxx = LLONG_MIN;
    long long miny = LLONG_MAX, maxy = LLONG_MIN;

    for (int i = 0; i < n; ++i) {
        long long xi, yi;
        cin >> xi >> yi;
        minx = min(minx, xi);
        maxx = max(maxx, xi);
        miny = min(miny, yi);
        maxy = max(maxy, yi);
    }

    long long X = maxx - minx;
    long long Y = maxy - miny;
    long long ans = (max(X, Y) + 1) / 2; // = ceil(max(X,Y)/2)

    cout << ans << '\n';
    return 0;
}

```

## 端っこのケース

- n=1（点が 1 個）なら X=Y=0 → ans=0。
- 座標が負でも `max − min` なので問題なし。
- 「切り上げ」をちゃんとしたいときは `(m+1)/2` で OK（整数除算の性質）。
