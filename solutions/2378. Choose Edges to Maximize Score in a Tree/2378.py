class Solution:
  def maxScore(self, edges: List[List[int]]) -> int:
    n = len(edges)
    graph = [[] for _ in range(n)]

    for i, (parent, weight) in enumerate(edges):
      if parent != -1:
        graph[parent].append((i, weight))

    takeRoot, notTakeRoot = self._dfs(graph, 0)
    return max(takeRoot, notTakeRoot)

  def _dfs(self, graph: List[List[int]], u: int) -> Tuple[int, int]:
    """
    Returns (the maximum sum at u if we take one u->v edge,
             the maximum sum at u if we don't take any child edge).
    """
    bestEdge = 0
    notTakeU = 0

    for v, w in graph[u]:
      takeV, notTakeV = self._dfs(graph, v)
      bestEdge = max(bestEdge, w + notTakeV - takeV)
      notTakeU += takeV

    return (bestEdge + notTakeU, notTakeU)
