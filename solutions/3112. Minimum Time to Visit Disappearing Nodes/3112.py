class Solution:
  def minimumTime(self, n: int, edges: List[List[int]], disappear: List[int]) -> List[int]:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    return self._dijkstra(graph, 0, disappear)

  def _dijkstra(self, graph: List[List[Tuple[int, int]]], src: int, disappear: List[int]) -> List[int]:
    dist = [math.inf] * len(graph)

    dist[src] = 0
    minHeap = [(dist[src], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if d > dist[u]:
        continue
      for v, w in graph[u]:
        if d + w < disappear[v] and d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))

    return [d if d != math.inf else -1
            for d in dist]
