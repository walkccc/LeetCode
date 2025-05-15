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
  def findCriticalAndPseudoCriticalEdges(self, n: int, edges: list[list[int]]) -> list[list[int]]:
    criticalEdges = []
    pseudoCriticalEdges = []

    # Record the index information, so edges[i] := (u, v, weight, index).
    for i in range(len(edges)):
      edges[i].append(i)

    # Sort by the weight.
    edges.sort(key=lambda x: x[2])

    def getMSTWeight(
            firstEdge: list[int],
            deletedEdgeIndex: int) -> int | float:
      mstWeight = 0
      uf = UnionFind(n)

      if firstEdge:
        uf.unionByRank(firstEdge[0], firstEdge[1])
        mstWeight += firstEdge[2]

      for u, v, weight, index in edges:
        if index == deletedEdgeIndex:
          continue
        if uf.find(u) == uf.find(v):
          continue
        uf.unionByRank(u, v)
        mstWeight += weight

      root = uf.find(0)
      if any(uf.find(i) != root for i in range(n)):
        return math.inf

      return mstWeight

    mstWeight = getMSTWeight([], -1)

    for edge in edges:
      index = edge[3]
      # Deleting the `edge` increases the weight of the MST or makes the MST
      # invalid.
      if getMSTWeight([], index) > mstWeight:
        criticalEdges.append(index)
      # If an edge can be in any MST, we can always add `edge` to the edge set.
      elif getMSTWeight(edge, -1) == mstWeight:
        pseudoCriticalEdges.append(index)

    return [criticalEdges, pseudoCriticalEdges]
