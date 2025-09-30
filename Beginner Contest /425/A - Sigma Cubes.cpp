#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    int sign = ( i % 2 == 0 ? 1 : -1);
    ans += sign * 1ll * i * i * i;

  }

  cout << ans << endl;

  return 0;
}
