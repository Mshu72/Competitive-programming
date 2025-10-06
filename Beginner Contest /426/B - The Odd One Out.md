## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  char ans = S[0];

  for (int i = 0; i < (int)S.size(); i++)
  {
    if(ans == S[i])continue;
    if(ans != S[i] && ans ==S[i+1] ){
      ans=S[i];
      break; 
    }
    if(ans==S[(int)S.size()-2] && ans !=S[(int)S.size()-1]){
      ans=S[(int)S.size()-1];
      break;
    }
  }

  cout <<ans<<endl;

  return 0;
}
```
## 別解
- 1. ソートを活用する方法
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  sort(S.begin(),S.end());
  if(S[0] != S[1]){cout << S[0] << endl;}
  else{cout << S.back << endl;}

  return 0
}
```
 
- 2. 各文字の回数をカウントする方法
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  map(char, int) mp;
  for(auto &nx : S){mp[nx]++;}
  for(auto &nx : mp){
    if(nx.second ==1){
    cout << nx.first << endl;
    }
  }
  return 0;
}
```
