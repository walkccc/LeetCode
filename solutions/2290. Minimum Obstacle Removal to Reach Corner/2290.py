class Solution:
  def minimumObstacles(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    minHeap = [(grid[0][0], 0, 0)]  # (d, i, j)
    dist = [[math.inf] * n for _ in range(m)]
    dist[0][0] = grid[0][0]

    while minHeap:
      d, i, j = heapq.heappop(minHeap)
      if i == m - 1 and j == n - 1:
        return d
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        newDist = d + grid[i][j]
        if newDist < dist[x][y]:
          dist[x][y] = newDist
          heapq.heappush(minHeap, (newDist, x, y))

    return dist[m - 1][n - 1]
