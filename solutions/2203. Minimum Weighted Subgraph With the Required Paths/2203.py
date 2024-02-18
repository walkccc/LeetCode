class Solution:
  def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
    graph = [[] for _ in range(n)]
    reversedGraph = [[] for _ in range(n)]

    for u, v, w in edges:
      graph[u].append((v, w))
      reversedGraph[v].append((u, w))

    def dijkstra(graph: List[List[Tuple[int, int]]], src: int) -> List[int]:
      dist = [math.inf] * n
      minHeap = [(0, src)]  # (d, u)
      while minHeap:
        d, u = heapq.heappop(minHeap)
        if dist[u] != math.inf:
          continue
        dist[u] = d
        for v, w in graph[u]:
          heapq.heappush(minHeap, (d + w, v))
      return dist

    fromSrc1 = dijkstra(graph, src1)
    fromSrc2 = dijkstra(graph, src2)
    fromDest = dijkstra(reversedGraph, dest)
    minWeight = min(a + b + c for a, b, c in zip(fromSrc1, fromSrc2, fromDest))
    return -1 if minWeight == math.inf else minWeight
