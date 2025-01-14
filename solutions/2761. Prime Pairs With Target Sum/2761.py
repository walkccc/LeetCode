class Solution:
  def findPrimePairs(self, n: int) -> list[list[int]]:
    isPrime = self._sieveEratosthenes(n + 1)
    return [[i, n - i] for i in range(2, n // 2 + 1)
            if isPrime[i] and isPrime[n - i]]

  def _sieveEratosthenes(self, n: int) -> list[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime


j
