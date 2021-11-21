class Solution:
  def minimumEffortPath(self, heights: List[List[int]]) -> int:
    m = len(heights)
    n = len(heights[0])
    dirs = [0, 1, 0, -1, 0]

    # diff[i][j] := max absolute difference to reach (i, j
    diff = [[inf] * n for _ in range(m)]
    seen = set()

    diff[0][0] = 0

    pq = [(diff[0][0], 0, 0)]  # (d, i, j)

    while pq:
      d, i, j = heapq.heappop(pq)
      if i == m - 1 and j == n - 1:
        return d
      seen.add((i, j))
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if (x, y) in seen:
          continue
        newDiff = abs(heights[i][j] - heights[x][y])
        maxDiff = max(diff[i][j], newDiff)
        if diff[x][y] > maxDiff:
          diff[x][y] = maxDiff
          heapq.heappush(pq, (diff[x][y], x, y))
