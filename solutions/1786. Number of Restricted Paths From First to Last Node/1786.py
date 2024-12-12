class Solution:
  def countRestrictedPaths(self, n: int, edges: list[list[int]]) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u - 1].append((v - 1, w))
      graph[v - 1].append((u - 1, w))

    return self._dijkstra(graph, 0, n - 1)

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      dst: int,
  ) -> int:
    kMod = 10**9 + 7
    # ways[i] := the number of restricted path from i to n
    ways = [0] * len(graph)
    # dist[i] := the distance to the last node of i
    dist = [math.inf] * len(graph)

    ways[dst] = 1
    dist[dst] = 0
    minHeap = [(dist[dst], dst)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if d > dist[u]:
        continue
      for v, w in graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))
        if dist[v] < dist[u]:
          ways[u] += ways[v]
          ways[u] %= kMod

    return ways[src]
