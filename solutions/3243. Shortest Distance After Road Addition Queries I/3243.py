class Solution:
  def shortestDistanceAfterQueries(
      self,
      n: int,
      queries: list[list[int]],
  ) -> list[int]:
    ans = []
    dist = list(range(n))
    graph = [[] for _ in range(n)]

    for i in range(n - 1):
      graph[i].append(i + 1)

    for u, v in queries:
      graph[u].append(v)
      if dist[u] + 1 < dist[v]:
        dist[v] = dist[u] + 1
        self._bfs(graph, v, dist)
      ans.append(dist[n - 1])

    return ans

  def _bfs(self, graph: list[list[int]], start: int, dist: list[int]) -> None:
    """
    Performs a BFS to update the shortest distances from the given `start` node
    to all other reachable nodes in the graph. It updates the `dist` vector
    with the new shortest distances.
    """
    q = collections.deque([start])
    while q:
      u = q.popleft()
      for v in graph[u]:
        if dist[u] + 1 < dist[v]:
          dist[v] = dist[u] + 1
          q.append(v)
