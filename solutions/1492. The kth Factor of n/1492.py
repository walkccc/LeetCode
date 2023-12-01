class Solution:
  def kthFactor(self, n: int, k: int) -> int:
    # If i is a divisor of n, then n // i is also a divisor of n. So, we can
    # find all the divisors of n by processing the numbers <= sqrt(n).
    factor = 1
    i = 0  # the i-th factor

    while factor < int(math.sqrt(n)):
      if n % factor == 0:
        i += 1
        if i == k:
          return factor
      factor += 1

    factor = n // factor
    while factor >= 1:
      if n % factor == 0:
        i += 1
        if i == k:
          return n // factor
      factor -= 1

    return -1
