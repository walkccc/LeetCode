class Solution:
  def minFallingPathSum(self, grid: List[List[int]]) -> int:
    n = len(grid)

    for i in range(1, n):
      (firstMinNum, firstMinIndex), (secondMinNum, _) = sorted(
          {(a, i) for i, a in enumerate(grid[i - 1])})[:2]
      for j in range(n):
        if j == firstMinIndex:
          grid[i][j] += secondMinNum
        else:
          grid[i][j] += firstMinNum

    return min(grid[-1])
