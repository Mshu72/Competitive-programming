#include <bits/stdc++.h>
using namespace std;

int main() {
  // 整数N,Mの受取り
  int N, M;
  cin >> N >> M;
  // 長さNの整数列Aの受取り
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  // Aの要素の総和を算出
  int sum = 0;
  for (auto &n : A) {
    sum += n;
  }
  // 総和からMの差を計算
  int dist = sum - M;
　// 総和からMの差が正数列Aに一つでもあればYesを出力して処理を終了
  for (int i = 0; i < N; i++) {
    if (A[i] == dist) {
      cout << "Yes\n";
      return 0;
    }
  }
  // 該当がなければNoを出力
  cout << "No\n";
  return 0;
}
