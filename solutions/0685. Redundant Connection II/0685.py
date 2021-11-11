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
  def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
    parents = [0] * (len(edges) + 1)
    nodeWithTwoParents = 0

    for u, v in edges:
      parents[v] += 1
      if parents[v] == 2:
        nodeWithTwoParents = v

    def findRedundantDirectedConnection(skippedEdgeIndex: int) -> List[int]:
      uf = UF(len(edges) + 1)

      for i, edge in enumerate(edges):
        if i == skippedEdgeIndex:
          continue
        if not uf.union(edge[0], edge[1]):
          return edge

      return []

    # if there is no edge with two parents
    # we don't have to skip any edge
    if nodeWithTwoParents == 0:
      return findRedundantDirectedConnection(-1)

    for i in range(len(edges))[::-1]:
      u, v = edges[i]
      if v == nodeWithTwoParents:
        # try to delete edges[i]
        if not findRedundantDirectedConnection(i):
          return edges[i]
