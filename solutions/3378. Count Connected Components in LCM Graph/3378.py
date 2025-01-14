class UnionFind:
  def __init__(self):
    self.id = {}
    self.rank = collections.Counter()

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
    if u not in self.id:
      self.id[u] = u
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def countComponents(self, nums: list[int], threshold: int) -> int:
    uf = UnionFind()

    for num in nums:
      for multiple in range(2 * num, threshold + 1, num):
        uf.unionByRank(num, multiple)

    return len(set(uf.find(num) for num in nums))
