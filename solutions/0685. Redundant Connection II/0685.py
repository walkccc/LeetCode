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
  def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
    ids = [0] * (len(edges) + 1)
    nodeWithTwoParents = 0

    for u, v in edges:
      ids[v] += 1
      if ids[v] == 2:
        nodeWithTwoParents = v

    def findRedundantDirectedConnection(skippedEdgeIndex: int) -> List[int]:
      uf = UF(len(edges) + 1)

      for i, edge in enumerate(edges):
        if i == skippedEdgeIndex:
          continue
        if not uf.union(edge[0], edge[1]):
          return edge

      return []

    # if there is no edge with two ids
    # we don't have to skip any edge
    if nodeWithTwoParents == 0:
      return findRedundantDirectedConnection(-1)

    for i in reversed(range(len(edges))):
      _, v = edges[i]
      if v == nodeWithTwoParents:
        # try to delete edges[i]
        if not findRedundantDirectedConnection(i):
          return edges[i]
