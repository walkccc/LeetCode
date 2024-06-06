class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> bool:
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
  def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
    uf = UnionFind(n + 1)

    for z in range(threshold + 1, n + 1):
      for x in range(z * 2, n + 1, z):
        uf.unionByRank(z, x)

    return [uf.find(a) == uf.find(b) for a, b in queries]
