## 解答
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    string pos = S.find('-');
    int I = stoi(S.substr(0, pos));
    int J = stoi(S.substr(pos + 1));

    if (J < 8) {
        cout << I << '-' << (J + 1) << '\n';
    } else if (I < 8 && J == 8) {
        cout << (I + 1) << '-' << 1 << '\n';
    } else {
        cout << 8 << '-' << 8 << '\n';
    }
    return 0;
}
```
## 解説
### `string pos = S.find('_')`を`auto pos = S.find('-');`にした場合  
`auto pos = S.find('-');` は、文字列 `S` の中から **文字 `'-'`（ハイフン）を最初に見つけた位置**を探して、そのインデックスを `pos` に入れます。

ポイントだけサクッと：

* `.find('-')` は **最初に一致した位置のインデックス**（0 始まり）を返します。
  例：`S = "12-34"` → `pos == 2`。
* 見つからなければ **`std::string::npos`** を返します（典型的には `size_t(-1)`）。
  そのため直後の `if (pos == string::npos)` で未検出を判定できます。
* 返り値の型は `std::string::size_type`（符号なし整数）で、`auto` によってこれが推論されています。
* 1 文字だけを探すので \*\*`'-'`（char リテラル）\*\*のオーバーロードが使われます（`"-"` のような C 文字列でも探せますが、1 文字なら `'-'` が最適）。
* 計算量は **O(|S|)**。線形時間で先頭から順に検索します。
* **最初のハイフンしか見ません。** もし複数ハイフンがあり「最後のハイフン」を取りたいなら `rfind('-')` を使います。

### よくある落とし穴

* `npos` は **符号なし**の最大値なので、`int` に代入して比較するとバグの元です。`auto`（= `size_type`）か `string::size_type` を使うのが安全。
* 入力が `"12—34"`（全角ダッシュやマイナス記号 `U+2212`）など **ASCII ハイフンでない場合**は見つかりません。UTF-8 で見た目が似ていても別文字です。
* ハイフンが先頭/末尾にあると `substr` が空になり、`stoi` が **例外**（`invalid_argument`）を投げます。必要なら追加バリデーションを。

### 参考：厳密に 1 個だけのハイフンを許す例

```cpp
auto pos = S.find('-');
if (pos == string::npos || pos == 0 || pos + 1 >= S.size() || S.rfind('-') != pos) {
    // 見つからない / 先頭 or 末尾 / ハイフンが複数
    cout << "invalid input\n";
    return 0;
}
```

この行自体は「区切り位置を見つける」ための標準的な書き方で、後続の `substr` + `stoi` と組み合わせて `"I-J"` の分割・数値化に使っています。

