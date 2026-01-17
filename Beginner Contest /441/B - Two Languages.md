## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

bool containsAll(const vector<char>& list, const string& w) {
    for (char c : w) {
        if (find(list.begin(), list.end(), c) == list.end()) {
            return false;
        }
    }
    return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  string s,t;
  cin >> s;
  cin >> t;
  vector<char> s_chr(n);
  for(int i = 0; i < n; i++){
    s_chr[i] = s[i];
  }
  vector<char> t_chr(m);
  for(int i = 0; i < m; i++){
    t_chr[i] = t[i];
  }
  int q;
  cin >> q;
  while(q--){
    string w;
    cin >> w;
    bool takahashi = false;
    bool aoki = false;
    if (containsAll(s_chr, w)){
      takahashi = true;
    }
    if (containsAll(t_chr, w)){
      aoki = true;
    }
    if (takahashi && aoki) {
      cout << "Unknown\n";
    } else if (takahashi) {
      cout << "Takahashi\n";
    } else if (aoki) {
      cout << "Aoki\n";
    } else {
      cout << "Unknown\n";
    }
    cout << endl;
  }
  return 0;
}
```

`std::find`の戻り値は、`[first,last]`  内のイテレータ i について、 `*i == value`  であるような最初のイテレータを返す。そのようなイテレータが見つからなかった場合は  `last`  を返す。
```cpp
if (find(list.begin(), list.end(), c) == list.end()) {
  return false;
}
```
この処理ではlistの最初から最後までの要素内でｃと一致するものを探しそのイテレータを返す。一致しない場合に最後のイテレータを返すためその場合だけfalseを返す。
