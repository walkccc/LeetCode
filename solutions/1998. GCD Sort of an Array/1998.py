class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return False
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1
    return True

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def gcdSort(self, nums: List[int]) -> bool:
    maxNum = max(nums)
    minPrimeFactors = self._sieveEratosthenes(maxNum + 1)
    uf = UnionFind(maxNum + 1)

    for num in nums:
      for primeFactor in self._getPrimeFactors(num, minPrimeFactors):
        uf.unionByRank(num, primeFactor)

    for a, b in zip(nums, sorted(nums)):
      # Can't swap nums[i] with sortedNums[i].
      if uf.find(a) != uf.find(b):
        return False

    return True

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
