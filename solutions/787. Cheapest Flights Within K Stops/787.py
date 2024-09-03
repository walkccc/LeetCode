class Solution:
  def findCheapestPrice(
      self,
      n: int,
      flights: list[list[int]],
      src: int,
      dst: int,
      k: int,
  ) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in flights:
      graph[u].append((v, w))

    return self._dijkstra(graph, src, dst, k)

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      dst: int,
      k: int,
  ) -> int:
    dist = [[math.inf for _ in range(k + 2)] for _ in range(len(graph))]

    dist[src][k + 1] = 0
    minHeap = [(dist[src][k + 1], src, k + 1)]  # (d, u, stops)

    while minHeap:
      d, u, stops = heapq.heappop(minHeap)
      if u == dst:
        return d
      if stops == 0 or d > dist[u][stops]:
        continue
      for v, w in graph[u]:
        if d + w < dist[v][stops - 1]:
          dist[v][stops - 1] = d + w
          heapq.heappush(minHeap, (dist[v][stops - 1], v, stops - 1))

    return -1
