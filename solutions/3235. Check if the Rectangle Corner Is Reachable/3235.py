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
  def canReachCorner(self, X: int, Y: int, circles: list[list[int]]) -> bool:
    n = len(circles)
    # Add two virtual nodes, where node n represents (0, 0) and node n + 1
    # represents (X, Y).
    uf = UnionFind(n + 2)

    # Iterate through each circle.
    for i, (x, y, r) in enumerate(circles):
      # Union the current circle with the node (0, 0) if the circle overlaps
      # with the left or top edges.
      if x - r <= 0 or y + r >= Y:
        uf.unionByRank(i, n)
      # Union the current circle with the node (X, Y) if the circle overlaps
      # with the right or bottom edges.
      if x + r >= X or y - r <= 0:
        uf.unionByRank(i, n + 1)
      # Union the current circle with previous circles if they overlap.
      for j in range(i):
        x2, y2, r2 = circles[j]
        if (x - x2)**2 + (y - y2)**2 <= (r + r2)**2:
          uf.unionByRank(i, j)

    # If nodes (0, 0) and (X, Y) are in the same union set, that means there's
    # a path of overlapping circles that connects the left or top edges to the
    # right or bottom edges, implying that (0, 0) cannot reach (X, Y).
    return uf.find(n) != uf.find(n + 1)
