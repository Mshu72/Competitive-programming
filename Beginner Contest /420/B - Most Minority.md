"" 解答
```C++
#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  // 各人の投票は「長さMの0/1文字列」
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  // 各人の得点
  vector<int> score(N, 0);

  // 各回（列j）ごとに採点する
  for (int j = 0; j < M; j++) {
    int x = 0;
    int y = 0;
    // j回目の0/1を数える
    for (int i = 0; i < N; i++){
      if (S[i][j] == '0') ++x;
      else ++y;
    }

    if (x == 0 || y == 0) {
      // 全員に1点
      for (int i = 0; i < N;i++) score[i]++;
    } else if ( x < y) {
      // 0が少数派 → 0に投票した人だけ+1
      for (int i = 0; i < N;i++) if(S[i][j] == '0') score[i]++; 
    } else {
       // 1が少数派 → 1に投票した人だけ+1
      for (int i = 0; i < N;i++) if(S[i][j] == '1') score[i]++; 
    } 
  }

  // 最大得点を求める
  int mx = *max_element(score.begin(), score.end());

  // 最大得点の人の番号(1-indexed)を空白区切りで出力
  bool first = true;
  for (int i = 0; i < N; i++) {
    if (mx == score[i]){
      if (!first) cout << ' ';
      cout << (i + 1);
      first = false
    }
  }


  return 0;

}
```
## 解説
- 入力：`N` 人、`M` 回、各人の投票列（0/1の文字列）
- 列 j ごとに 0 と 1 の人数を数える（x, y）
- ルールに従って該当者の score を加算
- すべての回が終わったら最大得点 mx を求め、mx の人を 1 からの番号で列挙
- 時間計算量は O(NM)（N ≤ 99, M ≤ 100 なので十分高速）。
- `N` は奇数なので `x == y` は起こりませんが、万一の拡張に備えてロジックはそのままでも問題ない構成です。
