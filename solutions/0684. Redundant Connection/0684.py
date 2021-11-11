class UF:
  def __init__(self, n: int):
    self.parent = [i for i in range(n + 1)]

  def union(self, u: int, v: int) -> bool:
    pu = self.find(u)
    pv = self.find(v)
    if pu == pv:
      return False

    self.parent[pu] = pv
    return True

  def find(self, u: int) -> int:
    if self.parent[u] != u:
      self.parent[u] = self.find(self.parent[u])
    return self.parent[u]


class Solution:
  def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
    uf = UF(len(edges))

    for edge in edges:
      if not uf.union(edge[0], edge[1]):
        return edge
