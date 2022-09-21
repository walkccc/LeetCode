class Solution:
  def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
    graph = [[] for _ in range(n)]
    minHeap = [(0, 0)]  # (d, u)
    dist = [maxMoves + 1] * n
    dist[0] = 0

    for u, v, cnt in edges:
      graph[u].append((v, cnt))
      graph[v].append((u, cnt))

    while minHeap:
      d, u = heapq.heappop(minHeap)
      # already takes maxMoves to reach u, can't explore anymore
      if dist[u] >= maxMoves:
        break
      for v, w in graph[u]:
        newDist = d + w + 1
        if newDist < dist[v]:
          dist[v] = newDist
          heapq.heappush(minHeap, (newDist, v))

    reachableNodes = sum(d <= maxMoves for d in dist)
    reachableSubnodes = 0

    for u, v, cnt in edges:
      # reachable nodes of e from u
      a = 0 if dist[u] > maxMoves else min(maxMoves - dist[u], cnt)
      # reachable nodes of e from v
      b = 0 if dist[v] > maxMoves else min(maxMoves - dist[v], cnt)
      reachableSubnodes += min(a + b, cnt)

    return reachableNodes + reachableSubnodes
