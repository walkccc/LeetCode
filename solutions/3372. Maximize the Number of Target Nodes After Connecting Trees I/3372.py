class Solution:
  def maxTargetNodes(
      self,
      edges1: list[list[int]],
      edges2: list[list[int]],
      k: int
  ) -> list[int]:
    graph1 = self._buildGraph(edges1)
    graph2 = self._buildGraph(edges2)
    maxReachableInGraph2 = 0

    if k > 0:
      for i in range(len(edges2) + 1):
        maxReachableInGraph2 = max(maxReachableInGraph2,
                                   self._dfs(graph2, i, -1, k - 1))

    return [maxReachableInGraph2 + self._dfs(graph1, i, -1, k)
            for i in range(len(edges1) + 1)]

  def _dfs(self, graph: list[list[int]], u: int, prev: int, k: int) -> int:
    """Returns the number of nodes that can be reached from u with k steps."""
    if k == 0:
      return 1
    res = 0
    for v in graph[u]:
      if v != prev:
        res += self._dfs(graph, v, u, k - 1)
    return 1 + res

  def _buildGraph(self, edges: list[list[int]]) -> list[list[int]]:
    graph = [[] for _ in range(len(edges) + 1)]
    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)
    return graph
