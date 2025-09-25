## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++)cin >> A[i];
  
  for(int i=N;i>=0;--i){
    int count =0;
    for (auto a:A){
      if(a >= i)count++;
    }
    if(count >= i){
      cout << i << endl;
      break;
    }
  }
```
