class Solution:
  def minimumWeight(
      self,
      n: int,
      edges: list[list[int]],
      src1: int,
      src2: int,
      dest: int,
  ) -> int:
    graph = [[] for _ in range(n)]
    reversedGraph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      reversedGraph[v].append((u, w))

    fromSrc1 = self._dijkstra(graph, src1)
    fromSrc2 = self._dijkstra(graph, src2)
    fromDest = self._dijkstra(reversedGraph, dest)
    minWeight = min(a + b + c for a, b, c in zip(fromSrc1, fromSrc2, fromDest))
    return -1 if minWeight == math.inf else minWeight

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
