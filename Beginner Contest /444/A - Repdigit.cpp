#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n%10;
    int nextN = n/10;
    int b = nextN %10;
    int lastN = nextN/10;
    if (a == b && a == lastN) {
      cout << "Yes\n" << endl;
    } else {
      cout << "No\n" << endl;
    }
  return 0;
}
