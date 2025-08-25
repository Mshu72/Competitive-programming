## 解答
```C++
#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  
  // 先にサイズ N を確保する
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  // 初期の sum = Σ min(Ak, Bk)
  long long sum = 0;
  for (int i = 0; i < N; i++) sum += min(A[i], B[i]);

  // Q 個のクエリをその場で処理
  for (int i = 0; i < Q; i++) {
    string c;
    int X, Y;
    cin >> c >> X >> Y;

    // 入力が 1-index の想定なので 0-index に直す
    --X;

    // 変更前のその位置の min
    long long befor = min(A[X], B[X]);

    // A か B を更新
    if (c == 'A') {
      A[x] = Y;
    } else {
      B[x] = Y;
    }

    // 変更後のその位置の min
    long long after = min(A[X], B[X]);
    
    // 差分だけ合計に加算（O(1)）
    sum += (after - befor);

    // 直後の合計を出力
    cout << sum << endl;

  }


  return 0;

}
```
## 解説
