#include <bits/stdc++.h>
using namespace std;

int main() {
  int s,a,b,x;
  cin >> s >> a >> b >> x;
  
  int t = x/(a+b);
  int r = x%(a+b);

  int ans =s* (t*a + min(r,a));

  cout << ans <<endl;
  return 0;
}
