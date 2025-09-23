## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> prereq(N);
    vector<vector<int>> dependents(N + 1);
    queue<int> q;
    vector<bool> learned(N + 1, false);
    int learned_count = 0;

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;
        prereq[i - 1] = {A, B};
        if (A == 0 && B == 0) {
            q.push(i);
            learned[i] = true;
            learned_count++;
        } else {
            dependents[A].push_back(i);
            dependents[B].push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : dependents[cur]) {
            if (learned[next]) continue;
            auto [A, B] = prereq[next - 1];
            if (learned[A] || learned[B]) {
                learned[next] = true;
                learned_count++;
                q.push(next);
            }
        }
    }

    cout << learned_count << endl;
    return 0;
}
```
## 解説

##  処理の流れ

1. **入力読み取り**

   ```cpp
   vector<pair<int, int>> prereq(N);
   vector<vector<int>> dependents(N + 1);
   queue<int> q;
   vector<bool> learned(N + 1, false);
   int learned_count = 0;
   ```

   * `prereq[i]` にスキル `i+1` の前提 `(Ai, Bi)` を格納
   * `dependents[x]` = 「スキル x を習得したら習得できる候補スキル」リスト
   * BFS 用の `queue` を用意
   * 習得済みかどうかを管理する `learned`

---

2. **初期スキルの登録**

   ```cpp
   if (A == 0 && B == 0) {
       q.push(i);
       learned[i] = true;
       learned_count++;
   } else {
       dependents[A].push_back(i);
       dependents[B].push_back(i);
   }
   ```

   * `(0,0)` のスキルは最初から習得済みとして `q` に追加
   * それ以外のスキルは「依存関係」を逆向きに登録

     * 例: スキル `i` が `(A, B)` に依存 → `dependents[A]` と `dependents[B]` に `i` を追加

---

3. **BFS による習得伝播**

   ```cpp
   while (!q.empty()) {
       int cur = q.front(); q.pop();
       for (int next : dependents[cur]) {
           if (learned[next]) continue;
           auto [A, B] = prereq[next - 1];
           if (learned[A] || learned[B]) {
               learned[next] = true;
               learned_count++;
               q.push(next);
           }
       }
   }
   ```

   * キューから取り出したスキル `cur` を習得済みとして、
     `dependents[cur]` のスキルをチェック。
   * そのスキル `next` の前提 `(A, B)` のどちらかが習得済みなら、新しく習得可能。
   * 習得したら `q` に入れてさらに伝播。

---

4. **結果出力**

   ```cpp
   cout << learned_count << endl;
   ```

   * 習得済みスキル数を出力。

---

## 計算量

* 各スキルと依存関係を一度ずつ処理するだけなので **O(N)**
* 制約 `N ≤ 2×10^5` でも十分高速に動作します。

---

## 動作例

### 入力

```
5
0 0
1 0
1 2
4 5
0 0
```

### 習得の流れ

* スキル1と5は `(0,0)` なので最初から習得済み
* スキル2は `1` に依存 → 習得
* スキル3は `(1,2)` に依存 → 習得
* スキル4は `(4,5)` に依存だが、5が習得済みなので習得

### 出力

```
5
```
