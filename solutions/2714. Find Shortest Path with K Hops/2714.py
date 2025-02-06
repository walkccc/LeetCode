class Solution:
  # Similar to 787. Cheapest Flights Within K Stops
  def shortestPathWithHops(
      self,
      n: int,
      edges: list[list[int]],
      s: int,
      d: int,
      k: int,
  ) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    return self._dijkstra(graph, s, d, k)

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      dst: int,
      k: int,
  ) -> int:
    dist = [[math.inf for _ in range(k + 1)] for _ in range(len(graph))]

    dist[src][k] = 0
    minHeap = [(dist[src][k], src, k)]  # (d, u, hops)

    while minHeap:
      d, u, hops = heapq.heappop(minHeap)
      if u == dst:
        return d
      if dist[u][hops] > d:
        continue
      for v, w in graph[u]:
        # Go from u -> v with w cost.
        if d + w < dist[v][hops]:
          dist[v][hops] = d + w
          heapq.heappush(minHeap, (dist[v][hops], v, hops))
        # Hop from u -> v with 0 cost.
        if hops > 0 and d < dist[v][hops - 1]:
          dist[v][hops - 1] = d
          heapq.heappush(minHeap, (dist[v][hops - 1], v, hops - 1))
