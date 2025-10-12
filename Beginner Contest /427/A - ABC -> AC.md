## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int L = s.size();
  int r = (L + 1) / 2;

  string ans = s.substr(0,r-1) + s.substr(r);

  cout << ans <<endl;
  return 0;
}
```
## 解説
与えられた文字の真ん中の文字を消した文字列を出力する。
上のコードは`substr`で真ん中より前までの文字列と真ん中より後の文字列を取り出して連結し出力する方法。
`erase`で削除する文字を指定する方法もある。
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int L = s.size();
  string ans = s.erase((L+1)/2);

  cout << ans <<endl;
  return 0;
}
```
