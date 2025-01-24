class Solution:
  def nonSpecialCount(self, l: int, r: int) -> int:
    maxRoot = math.isqrt(r)
    isPrime = self._sieveEratosthenes(maxRoot + 1)
    specialCount = 0

    for num in range(2, math.isqrt(r) + 1):
      if isPrime[num] and l <= num**2 <= r:
        specialCount += 1

    return r - l + 1 - specialCount

  def _sieveEratosthenes(self, n: int) -> list[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime
