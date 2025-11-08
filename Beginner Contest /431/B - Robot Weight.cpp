#include <bits/stdc++.h>
using namespace std;

// 任意の型の配列vに対して値xがあればtrue,なければfalseを返す
template <typename T>
bool has(const vector<T>& v, const T& x) {
    return find(v.begin(), v.end(), x) != v.end();
}

int main() {
  // 初めのロボットの重さと部品の種類を受け取る
  int x,n;
  cin >> x>>n;
  // 各部品ごとの重さを受け取る
  vector<int> w(n);
  for(int i=0;i<n;i++)cin >> w[i];
  // 出力の初期値に初めの重さを設定
  int ans = x;
  //　クエリ回数を受け取る
  int q;
  cin>>q;
  // ついている部品を管理する配列を設定
  vector<int> add;
  
  while(q--){
    // 部品番号を受け取る
    int p;
    cin>>p;
    // 部品を取り付けていない場合
    if (!has(add,p)) {
      // 部品Pの重さを出力値に加算して出力
      ans += w[p-1];
      cout << ans << endl;
      // 取り付けた部品番号を記録
      add.push_back(p);
    // 部品を取り付けている場合  
    } else {
      // 部品Pの重さを出力値から減算して出力
      ans -= w[p-1];
      cout << ans << endl;
      // 取り付けた部品のリストから部品Pを削除
      add.erase(find(add.begin(), add.end(), p));
    }
  }

return 0;
}
