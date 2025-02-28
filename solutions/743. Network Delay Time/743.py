class Solution:
  def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in times:
      graph[u - 1].append((v - 1, w))

    return self._dijkstra(graph, k - 1)

  def _dijkstra(self, graph: list[list[tuple[int, int]]], src: int) -> int:
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

    maxDist = max(dist)
    return maxDist if maxDist != math.inf else -1
