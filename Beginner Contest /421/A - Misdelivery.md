## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  int X;
  string Y;
  cin >> X >> Y;

  X -= 1;

  if (0 <= X && X < N && S[X] == Y) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
```
