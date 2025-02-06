class Solution:
  def minimumDistance(
      self,
      n: int,
      edges: list[list[int]],
      s: int,
      marked: list[int],
  ) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))

    dist = self._dijkstra(graph, s)
    ans = min(dist[u] for u in marked)
    return -1 if ans == math.inf else ans

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
  ) -> list[int]:
    dist = [math.inf] * len(graph)

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
