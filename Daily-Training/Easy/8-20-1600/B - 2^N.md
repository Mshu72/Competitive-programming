## 解答
```C++
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n
  cin >> n;

 cout << (long long)pow(2, n) <<endl;


  return 0;

}
```
## 解説
- `pow(2, n)` は `double` を返すので、整数にキャストするのが安全です。

- `n` が大きいと誤差が出る場合があります。

ビットシフトを使う場合
```C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << (1LL << n) << endl;

    return 0;
}
```
- `1LL << n `は「1 を左に n ビットシフト」＝ 2^n になります。

- `1LL` としておけば `long long `型に拡張され、大きめの n にも対応できます。

- 例えば n=10 のとき → 1024 が出力されます。
