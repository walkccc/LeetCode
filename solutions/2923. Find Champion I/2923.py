class Solution:
  def findChampion(self, grid: List[List[int]]) -> int:
    n = len(grid)
    inDegrees = [0] * n

    for i in range(n):
      for j in range(n):
        if i == j:
          continue
        if grid[i][j] == 1:
          inDegrees[j] += 1
        else:
          inDegrees[i] += 1

    return -1 if inDegrees.count(0) > 1 \
        else inDegrees.index(0)
