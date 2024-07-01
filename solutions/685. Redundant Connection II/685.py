class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> bool:
    i = self._find(u)
    j = self._find(v)
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

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
    ids = [0] * (len(edges) + 1)
    nodeWithTwoParents = 0

    for _, v in edges:
      ids[v] += 1
      if ids[v] == 2:
        nodeWithTwoParents = v

    def findRedundantDirectedConnection(skippedEdgeIndex: int) -> List[int]:
      uf = UnionFind(len(edges) + 1)

      for i, edge in enumerate(edges):
        if i == skippedEdgeIndex:
          continue
        if not uf.unionByRank(edge[0], edge[1]):
          return edge

      return []

    # If there is no edge with two ids, don't skip any edge.
    if nodeWithTwoParents == 0:
      return findRedundantDirectedConnection(-1)

    for i in reversed(range(len(edges))):
      _, v = edges[i]
      if v == nodeWithTwoParents:
        # Try to delete the edges[i].
        if not findRedundantDirectedConnection(i):
          return edges[i]
