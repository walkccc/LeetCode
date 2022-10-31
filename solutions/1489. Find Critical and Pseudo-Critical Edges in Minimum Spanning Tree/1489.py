class UnionFind:
  def __init__(self, n: int):
    self.id = list(range(n))
    self.rank = [0] * n

  def union(self, u: int, v: int) -> None:
    i = self.find(u)
    j = self.find(v)
    if i == j:
      return
    if self.rank[i] > self.rank[j]:
      i, j = j, i
    elif self.rank[i] == self.rank[j]:
      self.rank[j] += 1
    self.id[i] = j

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]


class Solution:
  def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
    criticalEdges = []
    pseudoCriticalEdges = []

    # Record the index information, so edges[i] := (u, v, weight, index)
    for i in range(len(edges)):
      edges[i].append(i)

    # Sort by weight
    edges.sort(key=lambda x: x[2])

    def getMSTWeight(firstEdge: List[int], deletedEdgeIndex: int) -> int:
      mstWeight = 0
      uf = UnionFind(n)

      if firstEdge:
        uf.union(firstEdge[0], firstEdge[1])
        mstWeight += firstEdge[2]

      for u, v, weight, index in edges:
        if index == deletedEdgeIndex:
          continue
        if uf.find(u) == uf.find(v):
          continue
        uf.union(u, v)
        mstWeight += weight

      root = uf.find(0)
      for i in range(n):
        if uf.find(i) != root:
          return math.inf

      return mstWeight

    mstWeight = getMSTWeight([], -1)

    for e in edges:
      index = e[3]
      # Deleting `e` makes the MST weight increase or can't form a MST
      if getMSTWeight([], index) > mstWeight:
        criticalEdges.append(index)
      # If an edge can be in any MST, we can always add `e` to the edge set
      elif getMSTWeight(e, -1) == mstWeight:
        pseudoCriticalEdges.append(index)

    return [criticalEdges, pseudoCriticalEdges]
