## 解説
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> pairs(K);
    unordered_map<int, int> count;
    vector<int> ans;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        pairs[i] = {a, b};
        count[a]++;
        if (count[a] == M){
          ans.push_back(a);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
```
## 解説
このコードは、**M 回目に到達した `a` を記録して出力する**という処理をシンプルに実装していて、基本的には正しいです。  
ただし、**重複追加の可能性がある**という点に注意が必要です。

---

## コードの処理概要（正しく動作する部分）

```cpp
unordered_map<int, int> count;
vector<int> ans;

for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    pairs[i] = {a, b};

    count[a]++;
    if (count[a] == M) {
        ans.push_back(a);  // M回目に到達したaを記録
    }
}
```

* `count[a]++` によって、`a` の出現回数をカウント。
* `count[a] == M` のときのみ `ans.push_back(a)`。

ここまでは OK です。

---

## 問題点：重複の可能性

理論上は、`count[a] == M` のときだけ `ans` に追加されるので「1回しか追加されない」ように思えます。

しかし、もし入力に次のような**重複したデータ行**が含まれると…

### 入力例（M=2）

```
5 2 6
1 0
1 1
1 2
1 3
2 0
2 1
```

`a=1` が 4回出現 ⇒ 2回目ときに `count[1]==2` になり `ans.push_back(1)`
→ OK

でも、\*\*このコードには「すでに `ans` に入れたかどうかのチェックがない」\*\*ため、もし入力の整合性が崩れていたり、バグで `count[a] == M` が **2回目以降にも通ってしまう状況**（例：何かがバグってカウントがリセットされた等）が起きたとき、重複する危険があります。

---

## 改善案：`unordered_set` で安全にする

```cpp
unordered_map<int, int> count;
unordered_set<int> already_added;
vector<int> ans;

for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    pairs[i] = {a, b};

    count[a]++;
    if (count[a] == M && already_added.find(a) == already_added.end()) {
        ans.push_back(a);
        already_added.insert(a);
    }
}
```

これで、「すでに追加済みの `a` は入れない」ことが保証され、**堅牢なコード**になります。

---

## 出力部

```cpp
for (int i = 0; i < ans.size(); i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
}
cout << endl;
```

* 空白区切り
* 最後に改行のみ


