## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,M;
  cin >>N>>M;
  vector<pair<int,int>> edges(M);
  for(int i=0;i<M;i++){
    int u,v;
    cin >>u >>v;
    //0-indexにする
    --u;--v;
    edges[i] = {u,v};
  }

    // 2^N 通りの2色塗りを全探索
    for (int mask = 0; mask < (1 << N); mask++) {
        // 削除が必要な辺数
        int del_count = 0;         
        for (const auto& [u, v] : edges) {
            // 各頂点の色
            int cu = (mask >> u) & 1;
            int cv = (mask >> v) & 1;
            if (cu == cv) {
                // 同色を結ぶ辺は削除する
                del_count++;
            }
        }
        ans = min(ans, del_count);
    }

  cout << ans <<endl;
  return 0;
}
```

  return 0;
}
