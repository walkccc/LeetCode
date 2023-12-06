class Solution:
  def minimumTime(self, grid: List[List[int]]) -> int:
    if grid[0][1] > 1 and grid[1][0] > 1:
      return -1

    m = len(grid)
    n = len(grid[0])
    dirs = [0, 1, 0, -1, 0]
    minHeap = [(0, 0, 0)]  # (time, i, j)
    seen = {(0, 0)}

    while minHeap:
      time, i, j = heapq.heappop(minHeap)
      if i == m - 1 and j == n - 1:
        return time
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if (x, y) in seen:
          continue
        extraWait = 1 if (grid[x][y] - time) % 2 == 0 else 0
        nextTime = max(time + 1, grid[x][y] + extraWait)
        heapq.heappush(minHeap, (nextTime, x, y))
        seen.add((x, y))
