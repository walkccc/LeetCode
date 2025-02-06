class Solution:
  def minimumEffortPath(self, heights: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(heights)
    n = len(heights[0])
    # diff[i][j] := the maximum absolute difference to reach (i, j)
    diff = [[math.inf] * n for _ in range(m)]
    seen = set()

    minHeap = [(0, 0, 0)]  # (d, i, j)
    diff[0][0] = 0

    while minHeap:
      d, i, j = heapq.heappop(minHeap)
      if i == m - 1 and j == n - 1:
        return d
      seen.add((i, j))
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if (x, y) in seen:
          continue
        newDiff = abs(heights[i][j] - heights[x][y])
        maxDiff = max(diff[i][j], newDiff)
        if diff[x][y] > maxDiff:
          diff[x][y] = maxDiff
          heapq.heappush(minHeap, (diff[x][y], x, y))
