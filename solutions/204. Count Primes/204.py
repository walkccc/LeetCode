class Solution:
  def countPrimes(self, n: int) -> int:
    if n <= 2:
      return 0
    return sum(self._sieveEratosthenes(n))

  def _sieveEratosthenes(self, n: int) -> list[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime
