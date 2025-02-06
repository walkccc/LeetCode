class Solution:
  def minCost(
      self,
      n: int,
      roads: list[list[int]],
      appleCost: list[int],
      k: int,
  ) -> list[int]:
    graph = [[] for _ in range(n)]

    for u, v, w in roads:
      graph[u - 1].append((v - 1, w))
      graph[v - 1].append((u - 1, w))

    return [self._dijkstra(graph, i, appleCost, k) for i in range(n)]

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      appleCost: list[int],
      k: int
  ) -> int:
    ans = math.inf
    dist = [math.inf] * len(graph)

    dist[src] = 0
    minHeap = [(dist[src], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if d > dist[u]:
        continue
      ans = min(ans, appleCost[u] + (k + 1) * d)
      for v, w in graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))

    return ans
