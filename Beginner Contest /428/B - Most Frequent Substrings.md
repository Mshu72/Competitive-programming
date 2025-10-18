## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >>n >>k;
  string s;
  cin >> s;
  map<string,int> mp;
  for (int i=0; i<=n-k;i++){
    string t = s.substr(i,k);
    mp[t]++;
  }

  int maxCount =0;
  for (auto& p:mp){
    maxCount = max(maxCount, p.second);
  }

  cout << maxCount << "\n";

  vector<string> ans;
  for(auto& x:mp){
    if(x.second == maxCount ){
      ans.push_back(x.first);
    }
  }

  for (int j=0;j<ans.size();j++){
    if(j>0){cout << " ";}
    cout << ans[j];
  }
  cout << endl;
  return 0;
}
```
## 解説
### 解答作成の方針
### 1. 長さ K の部分文字列を全列挙

- ループで i = 0 から N - K まで走査し、s.substr(i, K) を取り出す。

- これをキーとして出現回数をカウントする。

### 2. 出現回数をカウント

`map<string, int>` または `unordered_map<string, int> `を使って
`countMap[sub]++ `の形で記録。

### 3. 最大出現回数を求める

- カウントしたあとで、最大値 maxCount を見つける。

### 4. 最大回数の文字列を抽出

`for (auto &p : countMap) `で再走査し、
`p.second == maxCount `の文字列をリストに入れる。

### 5. 出力

- まず最大回数を出力。

- その後、該当する文字列（複数ある場合はすべて）を出力。
- 複数ある場合は文字列間に空白をつけて出力すること。
