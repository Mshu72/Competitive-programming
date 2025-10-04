## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string X,Y;
  cin >> X >> Y;
  
  if(Y == "Ocelot")cout << "Yes\n";
  else if(Y == "Serval" && X!="Ocelot") cout <<"Yes\n";
  else if(Y == "Lynx" && X=="Lynx") cout <<"Yes\n";
  else cout <<"No\n";

  return 0;
}
```
## 解説
- 別解1　バージョンに数字を割り当てる
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> mp;
  mp["Ocelot"]=1;
  mp["Servel"]=2;
  mp["Lynx"]=3;

  string X,Y;
  cin >> X >> Y;
  if(mp[X]>=mp[Y]){cout << "Yes\n";}
  else{cout << "No\n";}

  return 0;
}
