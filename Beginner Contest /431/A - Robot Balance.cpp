#include <bits/stdc++.h>
using namespace std;

int main() {
  // 頭と体のパーツの重さを受け取る
  int h,b;
  cin >> h>>b;
  // 頭と体のパーツの重さの差を算出
  int d = h-b;
  // 頭が重い場合は差分を表示する
  if (d > 0) {
    cout << d << endl;
  } else {
    cout << "0\n";
  }
  
return 0;
}
