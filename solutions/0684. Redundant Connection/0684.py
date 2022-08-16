class UF:
  def __init__(self, n: int):
    self.id = [i for i in range(n + 1)]

  def union(self, u: int, v: int) -> bool:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return False
    self.id[i] = j
    return True

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
    uf = UF(len(edges))

    for edge in edges:
      if not uf.union(edge[0], edge[1]):
        return edge
