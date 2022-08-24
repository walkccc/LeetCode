class Solution:
  def findBall(self, grid: List[List[int]]) -> List[int]:
    m = len(grid)
    n = len(grid[0])
    # dp[i] := status of i-th column
    # -1 := empty, 0 := b0, 1 := b1, ...
    dp = [i for i in range(n)]
    # ans[i] := i-th ball's final positio
    ans = [-1] * n

    for i in range(m):
      newDp = [-1] * n
      for j in range(n):
        # out of bound
        if j + grid[i][j] < 0 or j + grid[i][j] == n:
          continue
        if grid[i][j] == 1 and grid[i][j + 1] == -1 or \
                grid[i][j] == -1 and grid[i][j - 1] == 1:
          continue
        newDp[j + grid[i][j]] = dp[j]
      dp = newDp

    for i, ball in enumerate(dp):
      if ball != -1:
        ans[ball] = i

    return ans
