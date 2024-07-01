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
  def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
    uf = UnionFind(n)

    for u, v in edges:
      uf.unionByRank(u, v)

    return uf.find(source) == uf.find(destination)
