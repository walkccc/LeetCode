class Solution:
  def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
    graph1 = [[] for _ in range(n)]
    graph2 = [[] for _ in range(n)]  # reversed(graph1)

    for u, v, w in edges:
      graph1[u].append((v, w))
      graph2[v].append((u, w))

    def dijkstra(graph: List[List[Tuple[int, int]]], src: int) -> List[int]:
      minHeap = [(0, src)]  # (d, u)
      dist = [math.inf] * n
      while minHeap:
        d, u = heapq.heappop(minHeap)
        if dist[u] != math.inf:
          continue
        dist[u] = d
        for v, w in graph[u]:
          heapq.heappush(minHeap, (d + w, v))
      return dist

    fromSrc1 = dijkstra(graph1, src1)
    fromSrc2 = dijkstra(graph1, src2)
    fromDest = dijkstra(graph2, dest)
    minWeight = min(a + b + c for a, b, c in zip(fromSrc1, fromSrc2, fromDest))
    return -1 if minWeight == math.inf else minWeight
