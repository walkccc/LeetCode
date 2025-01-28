class Solution:
  def maximumPrimeDifference(self, nums: list[int]) -> int:
    kMax = 100
    isPrime = self._sieveEratosthenes(kMax + 1)
    minPrimeIndex = -1
    maxPrimeIndex = -1

    for i, num in enumerate(nums):
      if isPrime[num]:
        if minPrimeIndex == -1:
          minPrimeIndex = i
        maxPrimeIndex = i

    return maxPrimeIndex - minPrimeIndex

  def _sieveEratosthenes(self, n: int) -> list[bool]:
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n, i):
          isPrime[j] = False
    return isPrime
