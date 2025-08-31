## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

long long reverseNumber(long long n) {
    long long sign = (n < 0) ? -1 : 1;
    n = llabs(n);
    long long rev = 0;
    if (n == 0) return 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return sign * rev;
}

int main() {
    long long X, Y;
    cin >> X >> Y;

    vector<long long> A(11);
    A[1] = X;
    A[2] = Y;

    for (int i = 3; i <= 10; ++i) {
        A[i] = reverseNumber(A[i - 1] + A[i - 2]);
    }

    cout << A[10] << '\n';
    return 0;
}
```
## 解説
標準ライブラリには「整数をひっくり返す（reverse digits）」専用の関数はありません。
ただし、自作関数を簡単に作ることができます。

### 実装例1: 割り算と余りを使う方法

```cpp
#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main() {
    int x;
    cin >> x;
    cout << reverseNumber(x) << endl;
    return 0;
}
```

#### 実行例

```
入力: 13
出力: 31

入力: 10
出力: 1
```

---

### 実装例2: 文字列に変換して反転

```cpp
#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
    string s = to_string(n);
    std::reverse(s.begin(), s.end());
    return stoi(s); // 先頭の0は自動的に無視される
}

int main() {
    int x;
    cin >> x;
    cout << reverseNumber(x) << endl;
    return 0;
}
```

---

**ポイント**

* 例1は整数演算だけなので高速。
* 例2はコードが短く直感的。
* `10 → 1` のように末尾のゼロは自動的に消えます。



