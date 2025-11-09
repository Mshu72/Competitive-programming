#include <bits/stdc++.h>
using namespace std;

int main() {
  // 頭パーツ、体パーツ、作りたいロボットの数を受け取る
  long long n, m, k;
  cin >> n >> m >> k;
  // 各頭のパーツの重さを受け取る
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  // 各体のパーツの重さを受け取る
  vector<int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  // 頭と体の各パーツの重さをそれぞれ昇順に並べる
  sort(h.begin(),h.end());
  sort(b.begin(),b.end());
　// 作ったロボット数
  long long count = 0;
  // 使用する頭と体のパーツの番号
  long long i = 0, j = 0;
  // 頭か体のパーツが０になるまで処理を繰り返す
  while (i < n && j < m) {
    // 頭より体が重い場合は完成として数を数える
    if (h[i] <= b[j]) {
      count++;
      // 完成数が目標のK個に達成した場合はYesを出力し処理を終了
      if(count == k){
        cout << "Yes" << endl;
        return 0;
      }
      // 頭と体を次のパーツにする
      i++;
      j++;
    // 体より頭が重い場合
    } else {
      // 体のパーツを次のパーツにする
      j++;
    }
  }
  // 完成したロボットがｋ個にならない場合はNoを出力
  cout << "No\n";

return 0;
}
