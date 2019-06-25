import math

def gen_divisors(n):
  for i in range(2, math.floor(math.sqrt(n))):
    if n % i == 0:
      yield i