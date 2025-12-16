#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans=0;
  long long a=1;
  for(long long i=1;i<=n;i++){
    a*=i;
    if(a==n){
      ans=i;
      break;
    } 
  }
  
  cout<<ans<<endl;
  return 0;
}
