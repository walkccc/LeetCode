class Solution:
  def numPrimeArrangements(self, n: int) -> int:
    MOD = 1_000_000_007

    def factorial(n: int) -> int:
      fact = 1
      for i in range(2, n + 1):
        fact = fact * i % MOD
      return fact

    count = self._countPrimes(n)
    return factorial(count) * factorial(n - count) % MOD

  def _countPrimes(self, n: int) -> int:
    isPrime = [False] * 2 + [True] * (n - 1)
    for i in range(2, int(n**0.5) + 1):
      if isPrime[i]:
        for j in range(i * i, n + 1, i):
          isPrime[j] = False
    return sum(isPrime)
