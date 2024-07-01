class Solution:
  def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
    kMod = 1_000_000_007
    kMax = 10_000
    minPrimeFactors = self._sieveEratosthenes(kMax + 1)

    @functools.lru_cache(None)
    def fact(i: int) -> int:
      return 1 if i <= 1 else i * fact(i - 1) % kMod

    @functools.lru_cache(None)
    def inv(i: int) -> int:
      return pow(i, kMod - 2, kMod)

    @functools.lru_cache(None)
    def nCk(n: int, k: int) -> int:
      return fact(n) * inv(fact(k)) * inv(fact(n - k)) % kMod

    ans = []

    for n, k in queries:
      res = 1
      for freq in self._getPrimeFactorsCount(k, minPrimeFactors).values():
        res = res * nCk(n - 1 + freq, freq) % kMod
      ans.append(res)

    return ans

  def _sieveEratosthenes(self, n: int) -> List[int]:
    """Gets the minimum prime factor of i, where 1 < i <= n."""
    minPrimeFactors = [i for i in range(n + 1)]
    for i in range(2, int(n**0.5) + 1):
      if minPrimeFactors[i] == i:  # `i` is prime.
        for j in range(i * i, n, i):
          minPrimeFactors[j] = min(minPrimeFactors[j], i)
    return minPrimeFactors

  def _getPrimeFactorsCount(self, num: int, minPrimeFactors: List[int]) -> Dict[int, int]:
    count = collections.Counter()
    while num > 1:
      divisor = minPrimeFactors[num]
      while num % divisor == 0:
        num //= divisor
        count[divisor] += 1
    return count
