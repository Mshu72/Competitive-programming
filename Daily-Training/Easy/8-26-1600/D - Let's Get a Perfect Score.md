## 解答例
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<unsigned long long> mask(N, 0);
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    for (int j = 0; j < M; ++j) {
      if (s[j] == 'o') mask[i] |= (1ULL << j);
    }
  }

  const unsigned long long FULL = (M == 64 ? ~0ULL : ((1ULL << M) - 1)); // M≤30なので実質 (1ULL<<M)-1

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if ( (mask[i] | mask[j]) == FULL ) ++ans;
    }
  }

  cout << ans << '\n';
  return 0;
}
```
