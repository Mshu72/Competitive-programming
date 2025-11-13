import sys

input_price = input('insert: ')
if not input_price.isdecimal():
  print('整数を入力してください')
  sys.exsit()

product_price = input('product: ')
if not product_price.isdecimal():
  print('整数を入力してください')
  sys.exsit()
  
change = int(input_price) - int(product_price)

if change < 0:
  print('金額が不足しています')
  sys.exsit()

coin = [5000, 1000, 500, 100, 50, 10, 5, 1]

for i in coin:
  r = change // i
  change %= i
  print(str(i) + ': ' + str(r))
