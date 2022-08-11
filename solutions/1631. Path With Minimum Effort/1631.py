class Solution:
  def minimumEffortPath(self, heights: List[List[int]]) -> int:
    m = len(heights)
    n = len(heights[0])
    dirs = [0, 1, 0, -1, 0]
    # diff[i][j] := max absolute difference to reach (i, j
    diff = [[math.inf] * n for _ in range(m)]
    seen = set()

    minHeap = [(0, 0, 0)]  # (d, i, j)
    diff[0][0] = 0

    while minHeap:
      d, i, j = heapq.heappop(minHeap)
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
          heapq.heappush(minHeap, (diff[x][y], x, y))
