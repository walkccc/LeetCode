class Solution:
  def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
    kMod = 1_000_000_007
    dirs = [1, 0, -1, 0, 1]
    ans = 0
    # dp[i][j] := the number of paths to move the ball (i, j) out-of-bounds
    dp = [[0] * n for _ in range(m)]
    dp[startRow][startColumn] = 1

    for _ in range(maxMove):
      newDp = [[0] * n for _ in range(m)]
      for r in range(m):
        for c in range(n):
          if dp[r][c] > 0:
            for dx, dy in zip(dirs, dirs[1:]):
              x = r + dx
              y = c + dy
              if x < 0 or x == m or y < 0 or y == n:
                ans = (ans + dp[r][c]) % kMod
              else:
                newDp[x][y] = (newDp[x][y] + dp[r][c]) % kMod
      dp = newDp

    return ans
