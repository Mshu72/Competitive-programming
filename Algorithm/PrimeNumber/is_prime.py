import math

def is_Prime(n):
  if n <= 1:
    return False
  for i in (2, int(math.sqrt(n) + 1):
    if n % i == 0:
      return False
  return True
  
