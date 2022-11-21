class Solution:
  def countPrimes(self, n: int) -> int:
    if n <= 2:
      return 0

    isPrime = [False] * 2 + [True] * (n - 2)

    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False

    return sum(isPrime)
