class Solution:
  # Similar to 2203. Minimum Weighted Subgraph With the Required Paths
  def findAnswer(self, n: int, edges: list[list[int]]) -> list[bool]:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    from0 = self._dijkstra(graph, 0)
    from1 = self._dijkstra(graph, n - 1)
    return [from0[u] + w + from1[v] == from0[-1] or
            from0[v] + w + from1[u] == from0[-1]
            for u, v, w in edges]

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
  ) -> list[int]:
    dist = [10**9] * len(graph)

    dist[src] = 0
    minHeap = [(dist[src], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if d > dist[u]:
        continue
      for v, w in graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))

    return dist
