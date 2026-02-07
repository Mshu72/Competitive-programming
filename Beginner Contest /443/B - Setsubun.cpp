#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  
  int ans = 0;
  int sum = n;
  while(sum<k){
    n++;
    sum+=n;
    
    ans++;
  }
  
  cout << ans << endl;
  return 0;
}
