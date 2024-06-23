class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.sz = [1] * n

  def unionBySize(self, u: int, v: int) -> None:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return
    if self.sz[i] < self.sz[j]:
      self.sz[j] += self.sz[i]
      self.id[i] = j
    else:
      self.sz[i] += self.sz[j]
      self.id[j] = i

  def getSize(self, i: int) -> int:
    return self.sz[i]

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def canTraverseAllPairs(self, nums: List[int]) -> bool:
    n = len(nums)
    max_num = max(nums)
    maxPrimeFactor = self._sieveEratosthenes(max_num + 1)
    primeToFirstIndex = collections.defaultdict(int)
    uf = UnionFind(n)

    for i, num in enumerate(nums):
      for prime_factor in self._getPrimeFactors(num, maxPrimeFactor):
        if prime_factor in primeToFirstIndex:
          uf.unionBySize(primeToFirstIndex[prime_factor], i)
        else:
          primeToFirstIndex[prime_factor] = i

    return any(uf.getSize(i) == n for i in range(n))

  def _sieveEratosthenes(self, n: int) -> List[int]:
    """Gets the minimum prime factor of i, where 1 < i <= n."""
    minPrimeFactors = [i for i in range(n + 1)]
    for i in range(2, int(n**0.5) + 1):
      if minPrimeFactors[i] == i:  # `i` is prime.
        for j in range(i * i, n, i):
          minPrimeFactors[j] = min(minPrimeFactors[j], i)
    return minPrimeFactors

  def _getPrimeFactors(self, num: int, minPrimeFactors: List[int]) -> List[int]:
    primeFactors = []
    while num > 1:
      divisor = minPrimeFactors[num]
      primeFactors.append(divisor)
      while num % divisor == 0:
        num //= divisor
    return primeFactors
