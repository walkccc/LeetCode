class Solution:
  def matrixMedian(self, grid: List[List[int]]) -> int:
    noGreaterThanMedianCount = len(grid) * len(grid[0]) // 2 + 1
    l = 1
    r = int(1e6)

    while l < r:
      m = (l + r) // 2
      if sum(bisect_right(row, m) for row in grid) >= \
              noGreaterThanMedianCount:
        r = m
      else:
        l = m + 1

    return l
