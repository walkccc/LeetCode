class Graph:
  def __init__(self, n: int, edges: List[List[int]]):
    self.graph = [[] for _ in range(n)]
    for edge in edges:
      self.addEdge(edge)

  def addEdge(self, edge: List[int]):
    u, v, w = edge
    self.graph[u].append((v, w))

  def shortestPath(self, node1: int, node2: int) -> int:
    dist = [math.inf] * len(self.graph)

    dist[node1] = 0
    minHeap = [(dist[node1], node1)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if u == node2:
        return d
      for v, w in self.graph[u]:
        if d + w < dist[v]:
          dist[v] = d + w
          heapq.heappush(minHeap, (dist[v], v))

    return -1
