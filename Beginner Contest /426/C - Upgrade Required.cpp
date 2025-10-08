#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  // PCに現在のバージョンを詰め込む（初期化は１にする）
  vector<int> pc(N+1,1);
  // 古いバージョンのPCの台数
  pc[0] = 0;
  // 古いOSのバージョン
  int o = 1;

  // Q回処理を実行する
  while(Q--){
    // X,Yの受け取り
    int x, y;
    cin >> x >> y;
    // 返却値を初期化
    int res = 0;
    // 対象のバージョンの回数だけ処理を行う
    while(o <= x){
      // 返却値の設定
      res += pc[o];
      // 値を y 番目の要素に合算（集約）
      pc[y] += pc[o];
      o++;
    }
    // 返却処理を実行
    cout << res << endl;
  }

  return 0;
}
