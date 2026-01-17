#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, x, y;
  cin >> p >> q;
  cin >> x >> y;

  if (p <= x && p + 100 >= x && q <= y && q + 100 >= y) {
    cout << "Yes\n" << endl;
  } else {
    cout << "No\n" << endl;
  }
  return 0;
}
