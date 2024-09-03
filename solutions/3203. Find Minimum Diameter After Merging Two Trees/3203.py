class Solution:
  def minimumDiameterAfterMerge(
      self,
      edges1: list[list[int]],
      edges2: list[list[int]],
  ) -> int:
    diameter1 = self._getDiameter(edges1)
    diameter2 = self._getDiameter(edges2)
    combinedDiameter = (diameter1 + 1) // 2 + (diameter2 + 1) // 2 + 1
    return max(diameter1, diameter2, combinedDiameter)

  def _getDiameter(self, edges: list[list[int]]) -> int:
    n = len(edges) + 1
    graph = [[] for _ in range(n)]

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    maxDiameter = [0]
    self._maxDepth(graph, 0, -1, maxDiameter)
    return maxDiameter[0]

  # Similar to 1522. Diameter of N-Ary Tree
  def _maxDepth(
      self,
      graph: list[list[int]],
      u: int,
      prev: int,
      maxDiameter: list[int],
  ) -> int:
    """Returns the maximum depth of the subtree rooted at u."""
    maxSubDepth1 = 0
    maxSubDepth2 = 0
    for v in graph[u]:
      if v == prev:
        continue
      maxSubDepth = self._maxDepth(graph, v, u, maxDiameter)
      if maxSubDepth > maxSubDepth1:
        maxSubDepth2 = maxSubDepth1
        maxSubDepth1 = maxSubDepth
      elif maxSubDepth > maxSubDepth2:
        maxSubDepth2 = maxSubDepth
    maxDiameter[0] = max(maxDiameter[0], maxSubDepth1 + maxSubDepth2)
    return 1 + maxSubDepth1
