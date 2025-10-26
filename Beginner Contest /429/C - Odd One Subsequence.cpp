#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力受取り
  int N;
  cin >> N;
　// 正数列Aの受取り
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
　// Aの各値ごとに出現回数をカウント
  vector<long long> freq(N+1, 0);
  for (int a : A) freq[a]++;

  long long ans=0;
  // 出現回数が2回以上のものに対して出力値の計算処理を行う
  for (int i = 1; i <= N; i++) {
    long long c = freq[i];
    if(c>=2){
      ans += c * (c - 1) / 2 * (N - c);
    }
  }

  cout << ans <<endl;

  return 0;
}
