## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;
static inline int digit_sum(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    long long N;
    if (!(cin >> N)) return 0;

    int ans = 1;
    for (int i = 0; i < N-1; ++i) {
        ans += digit_sum(ans);
    }

    cout << ans << '\n';
    return 0;
}
```

