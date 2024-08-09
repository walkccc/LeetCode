class Solution:
  def countPaths(self, n: int, roads: List[List[int]]) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in roads:
      graph[u].append((v, w))
      graph[v].append((u, w))

    return self._dijkstra(graph, 0, n - 1)

  def _dijkstra(self, graph: List[List[Tuple[int, int]]], src: int, dst: int) -> int:
    kMod = 10**9 + 7
    ways = [0] * len(graph)
    dist = [math.inf] * len(graph)

    ways[src] = 1
    dist[src] = 0
    minHeap = [(dist[src], src)]

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if d > dist[u]:
        continue
      for v, w in graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          ways[v] = ways[u]
          heapq.heappush(minHeap, (dist[v], v))
        elif d + w == dist[v]:
          ways[v] += ways[u]
          ways[v] %= kMod

    return ways[dst]
