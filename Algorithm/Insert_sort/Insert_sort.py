data = [6, 15, 4, 2, 8, 5, 11, 9, 7, 13]

for i in range(1, len(data)):
  // 現在のデータを一時的に記録する
  temp = data[i]
  
  j = i - 1
  while (j >= 0) and (data[j] > temp):
    // 要素を一ずつ後ろにずらす
    data[j + 1] = data[j]
    j -= i
  // 一時的な領域から戻す
  data[j + 1] = temp

print(data)
