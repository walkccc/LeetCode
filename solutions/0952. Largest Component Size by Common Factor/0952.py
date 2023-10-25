class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def largestComponentSize(self, nums: List[int]) -> int:
    ans = 0
    uf = UnionFind(max(nums) + 1)
    count = collections.Counter()

    for num in nums:
      for x in range(2, int(math.sqrt(num) + 1)):
        if num % x == 0:
          uf.unionByRank(num, x)
          uf.unionByRank(num, num // x)

    for num in nums:
      numRoot = uf.find(num)
      count[numRoot] += 1
      ans = max(ans, count[numRoot])

    return ans
