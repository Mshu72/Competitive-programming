``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for(int i=0;i<n;i++) {
    int t;
    cin >>t;
    a.push_back({t, i+1});
  }

  sort(a.begin(), a.end());

  for(int i=0;i<3;i++) {
   if (i>0) cout << " ";
   cout << a[i].second; 
  }
  cout << endl;

  return 0;
}
```

- ポイント①  
`vector<pair<int, int>> a(n);`とするとサイズが n の配列を確保する。  
その後、`a.push_back({t, i});`すると  
　最初の n 個 → 未初期化（0,0） 
　さらに n 個 → 入力したデータ  
→ 合計 2n 個 要素が入ってしまいます。
  その結果、sort すると (0,0) が先頭に来てしまいます。

- ポイント②
  ## pair型のソート処理
  `pair<A, B> p, q(p<q) `に対してsortした場合は次のように評価されます：

  1. `p.first < q.first` なら `true`
  2. `p.first > q.first` なら `false`
  3. `p.first == q.first` のとき `p.second < q.second`

  つまり：

  ### first を最優先、同じなら second で比較

---

  もし比較方法を変えたい場合
  ### 1. `second` でソートしたい
  ```cpp
  sort(v.begin(), v.end(), [](auto a, auto b) {
      return a.second < b.second;
  });
  ```
  ### 2. first 降順、second 昇順
  ```cpp
  sort(v.begin(), v.end(), [](auto a, auto b) {
      if (a.first != b.first) return a.first > b.first;
      return a.second < b.second;
  });
  ```
    
