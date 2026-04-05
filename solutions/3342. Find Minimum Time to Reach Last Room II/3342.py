class Solution:
  # Similar to 3341. Find Minimum Time to Reach Last Room I
  def minTimeToReach(self, moveTime: list[list[int]]) -> int:
    return self._dijkstra(moveTime,
                          (0, 0),
                          (len(moveTime) - 1, len(moveTime[0]) - 1))

  def _dijkstra(
      self,
      moveTime: list[list[int]],
      src: tuple[int, int],
      dst: tuple[int, int]
  ) -> int:
    DIRS = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(moveTime)
    n = len(moveTime[0])
    dist = [[math.inf] * n for _ in range(m)]

    dist[0][0] = 0
    minHeap = [(0, src)]  # (d, (ux, uy))

    while minHeap:
      d, u = heapq.heappop(minHeap)
      if u == dst:
        return d
      i, j = u
      if d > dist[i][j]:
        continue
      for dx, dy in DIRS:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        newDist = max(moveTime[x][y], d) + (i + j) % 2 + 1
        if newDist < dist[x][y]:
          dist[x][y] = newDist
          heapq.heappush(minHeap, (newDist, (x, y)))

    return -1
