## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int a = stoi(S.substr(3));

  if ((a >= 1 && a <= 315) || (a >= 317 && a <= 349)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
```
---
## 解説
`int a = stoi(S.substr(3));` は、

1. `S.substr(3)`
   文字列 `S` の**先頭から数えて4文字目以降**（0始まりのインデックス3）を末尾まで切り出します。
   例: `S = "ABC123"` → `S.substr(3)` は `"123"`

2. `stoi(...)`
   その切り出した文字列を**10進整数**として解釈し、`int` に変換します。
   例: `stoi("123")` → `123`

なので、上の例なら `a` には `123` が代入されます。

---

## よくある落とし穴（重要）

* **長さが足りない**
  `S.size() < 3` のとき `S.substr(3)` は `pos > size()` で `std::out_of_range` を投げます。
  `S.size() == 3` なら空文字列が返り、`stoi("")` は `std::invalid_argument` を投げます。
* **数字で始まっていない**
  例: `"12a3"` は `stoi` 自体は `12` まで読めますが、全てが数字である保証はありません。完全一致を確認したいなら `pos` 引数で消費文字数を確認します（下記参照）。
* **範囲外**
  値が `int` の範囲を超えると `std::out_of_range`。

---

## 安全に書く例

```cpp
int a = 0;
if (S.size() >= 4) {
  size_t pos = 0;
  try {
    string t = S.substr(3);          // 4文字目以降
    a = stoi(t, &pos, 10);           // 10進で変換
    if (pos != t.size()) {
      // 末尾に数字以外が混ざっていた（例: "123abc"）
      // 必要に応じてエラー処理
    }
  } catch (const std::invalid_argument&) {
    // 数字が1文字もなかった
  } catch (const std::out_of_range&) {
    // intの範囲外
  }
} else {
  // 文字数不足（4文字未満）
}
```

### `stoi` のシグネチャ（覚えておくと便利）

```cpp
int stoi(const string& str, size_t* pos = nullptr, int base = 10);
```

* `pos`：何文字読み取ったかを返す（不要なら `nullptr` のままでOK）
* `base`：基数（2〜36、既定は10）

---

## 参考メモ

* 先頭の空白は無視されます（例: `"  42"` → 42）。
* `+`/`-` の符号はOK（例: `"-17"` → -17）。
* 全角数字は読めません（ASCII数字のみ）。
