class Solution:
  def reachableNodes(
      self,
      edges: list[list[int]],
      maxMoves: int,
      n: int,
  ) -> int:
    graph = [[] for _ in range(n)]
    dist = [maxMoves + 1] * n

    for u, v, cnt in edges:
      graph[u].append((v, cnt))
      graph[v].append((u, cnt))

    reachableNodes = self._dijkstra(graph, 0, maxMoves, dist)
    reachableSubnodes = 0

    for u, v, cnt in edges:
      # the number of reachable nodes of (u, v) from `u`
      a = 0 if dist[u] > maxMoves else min(maxMoves - dist[u], cnt)
      # the number of reachable nodes of (u, v) from `v`
      b = 0 if dist[v] > maxMoves else min(maxMoves - dist[v], cnt)
      reachableSubnodes += min(a + b, cnt)

    return reachableNodes + reachableSubnodes

  def _dijkstra(
      self,
      graph: list[list[tuple[int, int]]],
      src: int,
      maxMoves: int,
      dist: list[int],
  ) -> int:
    dist[src] = 0
    minHeap = [(dist[src], src)]  # (d, u)

    while minHeap:
      d, u = heapq.heappop(minHeap)
      # Already took `maxMoves` to reach `u`, so can't explore anymore.
      if dist[u] >= maxMoves:
        break
      if d > dist[u]:
        continue
      for v, w in graph[u]:
        newDist = d + w + 1
        if newDist < dist[v]:
          dist[v] = newDist
          heapq.heappush(minHeap, (newDist, v))

    return sum(d <= maxMoves for d in dist)
