## 解答

```cpp
#include<bits/stdc++.h>
using namespace std;
  int q;
  cin >> q;

  priority_queue<int, vector<int>, greater<>> pq;
  while(q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      pq.push(x);
    } else {
      int x = pq.top();
      pq.pop();
      cout << x <<'\n';
    }
  }

int main() {

}
```

## 解説
- 最初に整数 `q` を読み込みます。これは**クエリ（操作）の回数**です。
- その後、`q` 回くり返して、
    - `type == 1` のときは次の整数 `x` を読み込んで**入れる**（挿入）
    - `type == 2` のときは**最小の値を取り出して表示し、取り除く**
- この「最小の値をすぐに取り出せる入れ物」として **優先度付きキュー（priority_queue）** を使っています。

# キモ：priority_queue と min-heap

```cpp
priority_queue<int, vector<int>, greater<>> pq;

```

- `priority_queue` は「一番“優先度が高い”要素をすぐに取り出せる」データ構造です。
    
    デフォルトは **最大値が最優先**（max-heap）ですが、
    
- 第3テンプレート引数に `greater<>` を渡すことで、**最小値が最優先**になります（min-heap）。
    - 初学者向けには `greater<int>` と書くほうが分かりやすいです。

これにより、

- `pq.push(x);` で値を入れる（自動的に並べ替えられる）
- `pq.top();` で**最小値を参照**（取り除かない）
- `pq.pop();` で**最小値を削除**
    
    ができます。
    

# 1 回の処理の流れ

```cpp
int type;
cin >> type;
if (type == 1) {
  int x;
  cin >> x;
  pq.push(x);       // x を入れる
} else {
  int x = pq.top(); // 今ある中で最小
  pq.pop();         // 取り除く
  cout << x << '\n';
}

```

- `type == 1` → 値を入れるだけ
- `type == 2` → 最小値を表示して消す

# 例

入力

```
5
1 10
1 3
2
1 7
2

```

処理

- 1 10 → {10}
- 1 3 → {3,10}
- 2 → 最小は 3 を出力 → {10}
- 1 7 → {7,10}
- 2 → 最小は 7 を出力 → {10}

出力

```
3
7

```

# 計算量（速さの目安）

- `push` / `pop` は **O(log n)**（`n` は入っている要素数）
- `top` は **O(1)**
- 実用上とても速く、`q` が大きくても安心です。

# 注意点（落とし穴）

- *空のときに `top()` / `pop()` を呼ぶと未定義動作（クラッシュなど）**です。
    
    コンテスト問題では普通「`type==2` のときキューは空でない」と保証されますが、汎用コードでは次のように守るのが安全です。
    

```cpp
if (!pq.empty()) {
  cout << pq.top() << '\n';
  pq.pop();
} else {
  // 空のときの挙動を決めておく（例：何もしない、エラー出力 など）
}

```

- 入出力が多いときは高速化設定を入れるとより安定します。

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);

```
