解答例
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    sort(x.begin(), x.end());
    for (int i = 0; i < (int) x.size(); i++) {
        if (x[i] > '0') {
            swap(x[0], x[i]);
            break;
        }
    }
    cout << x << endl;
}
```
`swap(a,b)`は`a`と`b`を入れ替える処理
覚えていれば解けるが覚えていない場合はひたすら回す。
例
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string x;
  cin >> x;
  vector<char> digits;
  for(int i = 0; i < x.length(); i++) {
    digits.push_back(x[i]);
  }
  sort(digits.begin(), digits.end());
  
  int firstNonZero = -1;
  for(int i = 0; i < digits.size(); i++) {
    if(digits[i] != '0') {
      firstNonZero = i;
      break;
    }
  }
  
  string result = "";
  if(firstNonZero != -1) {
    result += digits[firstNonZero];
    for(int i = 0; i < digits.size(); i++) {
      if(i != firstNonZero) {
        result += digits[i];
      }
    }
  } else {
    result = x;
  }
  
  cout << result << endl;
  return 0;
}
```
