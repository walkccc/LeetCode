class Solution:
  def minimumDistance(self, n: int, edges: List[List[int]], s: int, marked: List[int]) -> int:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))

    dist = self._dijkstra(graph, s)
    ans = min(dist[u] for u in marked)
    return -1 if ans == math.inf else ans

  def _dijkstra(self, graph: List[List[Tuple[int, int]]], src: int) -> List[int]:
    dist = [math.inf] * len(graph)

    dist[src] = 0
    minHeap = [(dist[src], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      for v, w in graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))

    return dist
