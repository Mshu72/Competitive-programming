## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cuts = {0}; // 最初の切れ込み(12時=0°)
  int cur = 0;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    cur = (cur + a) % 360; // 累積角度
    cuts.push_back(cur);   // 切れ込み位置を追加
  }

  sort(cuts.begin(), cuts.end());

  int mx = 0;
  for (int i = 0; i + 1 < (int)cuts.size(); i++) {
    mx = max(mx, cuts[i + 1] - cuts[i]);
  }
  // 最後の切れ込みから360°→0°への巻き差
  mx = max(mx, 360 - cuts.back());

  cout << mx << "\n";
  return 0;
}
```
