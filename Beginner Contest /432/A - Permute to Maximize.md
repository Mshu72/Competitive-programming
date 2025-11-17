```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  vector<int>ans;
  ans.push_back(a);
  ans.push_back(b);
  ans.push_back(c);
  sort(ans.begin(), ans.end());
  reverse(ans.begin(),ans.end());
  int result = 100*ans[0] + 10*ans[1] + ans[2];
  cout << result <<endl;
  return 0;
}
```
わざわざ1つずつ詰めなくてもいい。また配列に入れているのソートしたら順番に出すだけで良い。
解答例
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> ans = {a, b, c};
  sort(ans.begin(), ans.end());
  cout << ans[2] << ans[1] << ans[0] << endl;
  return 0;
}
```
