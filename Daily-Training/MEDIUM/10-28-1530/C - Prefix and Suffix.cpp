#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  string S, T;
  cin >> S >> T;

  bool prefix = false;
  bool suffix = false;

  if (T.substr(0,N) == S) prefix = true;
  if (T.substr(M-N) == S) suffix = true;

  if (prefix && suffix) cout << "0\n";
  else if (prefix && !suffix) cout << "1\n";
  else if (!prefix && suffix) cout << "2\n";
  else cout << "3\n";

  return 0;
}
