class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> None:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return False
    if self.rank[i] < self.rank[j]:
      self.id[i] = self.id[j]
    elif self.rank[i] > self.rank[j]:
      self.id[j] = self.id[i]
    else:
      self.id[i] = self.id[j]
      self.rank[j] += 1
    return True

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
    uf = UnionFind(len(edges) + 1)

    for edge in edges:
      if not uf.unionByRank(edge[0], edge[1]):
        return edge
