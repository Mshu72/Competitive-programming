## 解答
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> L(N);
  for(int i=0;i<N;i++)cin >> L[i];

  int X = 0,Y=0;

  for(int i=0;i<N;i++){
    if(L[i]==1){
      X=i;
      break;
    }
  }

  for(int j=N-1;j>=0;j--){
    if(L[i]==1){
      Y=j;
      break;
    }
  }
  
  cout << Y-X<<endl;
  
  return 0;
}
```
## 解説
全体的な意図は「配列 L の中で 1 が最初に出てくる位置と、最後に出てくる位置を求めて、その差を出力する」
