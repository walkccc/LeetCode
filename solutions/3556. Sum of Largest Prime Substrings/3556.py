class Solution:
  def sumOfLargestPrimes(self, s: str) -> int:
    primes = set()
    n = len(s)

    for i in range(n):
      for j in range(i + 1, n + 1):
        num = int(s[i:j])
        if num not in primes and self._isPrime(num):
          primes.add(num)

    top3 = sorted(primes, reverse=True)[:3]
    return sum(top3)

  def _isPrime(self, n: int) -> bool:
    return n > 1 and all(n % i != 0 for i in range(2, math.isqrt(n) + 1))
