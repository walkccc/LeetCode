class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n
    # 2^17 - 1 is the minimum number in the form 2^x - 1 > 10^5.
    self.weight = [(1 << 17) - 1] * n

  def unionByRank(self, u: int, v: int, w: int) -> None:
    i = self._find(u)
    j = self._find(v)
    newWeight = self.weight[i] & self.weight[j] & w
    self.weight[i] = newWeight
    self.weight[j] = newWeight
    if i == j:
      return
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1

  def getMinCost(self, u: int, v: int) -> int:
    if u == v:
      return 0
    i = self._find(u)
    j = self._find(v)
    return self.weight[i] if i == j else -1

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def minimumCost(
      self,
      n: int,
      edges: list[list[int]],
      query: list[list[int]],
  ) -> list[int]:
    uf = UnionFind(n)

    for u, v, w in edges:
      uf.unionByRank(u, v, w)

    return [uf.getMinCost(u, v) for u, v in query]
