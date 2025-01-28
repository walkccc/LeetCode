class Solution:
  def minimumTime(
      self,
      n: int,
      edges: list[list[int]],
      disappear: list[int],
  ) -> list[int]:
    graph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      graph[v].append((u, w))

    return self._dijkstra(graph, 0, disappear)

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      disappear: list[int],
  ) -> list[int]:
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
