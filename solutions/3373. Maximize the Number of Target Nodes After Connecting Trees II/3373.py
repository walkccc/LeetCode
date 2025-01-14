class Solution:
  def maxTargetNodes(
      self,
      edges1: list[list[int]],
      edges2: list[list[int]]
  ) -> list[int]:
    n = len(edges1) + 1
    m = len(edges2) + 1
    graph1 = self._buildGraph(edges1)
    graph2 = self._buildGraph(edges2)
    parity1 = [False] * n
    parity2 = [False] * m  # placeholder (parity2 is not used)
    even1 = self._dfs(graph1, 0, -1, parity1, True)
    even2 = self._dfs(graph2, 0, -1, parity2, True)
    odd1 = n - even1
    odd2 = m - even2

    # Can connect the current node in tree1 to either an even node or an odd
    # node in tree2.
    return [(even1 if parity1[i] else odd1) + max(even2, odd2)
            for i in range(n)]

  def _dfs(
      self,
      graph: list[list[int]],
      u: int,
      prev: int,
      parity: list[bool],
      isEven: bool
  ) -> int:
    """
    Returns the number of nodes that can be reached from u with even steps.
    """
    res = 1 if isEven else 0
    parity[u] = isEven
    for v in graph[u]:
      if v != prev:
        res += self._dfs(graph, v, u, parity, not isEven)
    return res

  def _buildGraph(self, edges: list[list[int]]) -> list[list[int]]:
    graph = [[] for _ in range(len(edges) + 1)]
    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)
    return graph
