class Solution:
  def minimumCost(self, start: List[int], target: List[int], specialRoads: List[List[int]]) -> int:
    return self.dijkstra(specialRoads, *start, *target)

  def dijkstra(self, specialRoads: List[List[int]], srcX: int, srcY: int, dstX: int, dstY: int) -> int:
    n = len(specialRoads)
    # dist[i] := min dist of (srcX, srcY) -> specialRoads[i](x2, y2)
    dist = [math.inf] * n
    minHeap = []  # (d, u)

    # (srcX, srcY) -> (x1, y1) -> cost -> (x2, y2)
    for u, (x1, y1, _, _, cost) in enumerate(specialRoads):
      d = abs(x1 - srcX) + abs(y1 - srcY) + cost
      dist[u] = d
      heapq.heappush(minHeap, (dist[u], u))

    while minHeap:
      d, u = heapq.heappop(minHeap)
      _, _, ux2, uy2, _ = specialRoads[u]
      for v in range(n):
        if v == u:
          continue
        vx1, vy1, _, _, vcost = specialRoads[v]
        # (ux2, uy2) -> (vx1, vy1) -> vcost -> (vx2, vy2)
        newDist = d + abs(vx1 - ux2) + abs(vy1 - uy2) + vcost
        if newDist < dist[v]:
          dist[v] = newDist
          heapq.heappush(minHeap, (dist[v], v))

    ans = abs(dstX - srcX) + abs(dstY - srcY)
    for u in range(n):
      _, _, x2, y2, _ = specialRoads[u]
      # (srcX, srcY) -> (x2, y2) -> (dstX, dstY).
      ans = min(ans, dist[u] + abs(dstX - x2) + abs(dstY - y2))

    return ans
