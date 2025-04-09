class Solution:
  def maxCollectedFruits(self, fruits: list[list[int]]) -> int:
    n = len(fruits)

    def getTopLeft() -> int:
      return sum(fruits[i][i] for i in range(n))

    def getTopRight() -> int:
      # dp[i][j] := the number of fruits collected from (0, n - 1) to (i, j)
      dp = [[0] * n for _ in range(n)]
      dp[0][-1] = fruits[0][-1]
      for x in range(n):
        for y in range(n):
          if x >= y and (x, y) != (n - 1, n - 1):
            continue
          for dx, dy in [(1, -1), (1, 0), (1, 1)]:
            i = x - dx
            j = y - dy
            if i < 0 or i == n or j < 0 or j == n:
              continue
            if i < j < n - 1 - i:
              continue
            dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y])
      return dp[-1][-1]

    def getBottomLeft() -> int:
      # dp[i][j] := the number of fruits collected from (n - 1, 0) to (i, j)
      dp = [[0] * n for _ in range(n)]
      dp[-1][0] = fruits[-1][0]
      for y in range(n):
        for x in range(n):
          if x <= y and (x, y) != (n - 1, n - 1):
            continue
          for dx, dy in [(-1, 1), (0, 1), (1, 1)]:
            i = x - dx
            j = y - dy
            if i < 0 or i == n or j < 0 or j == n:
              continue
            if j < i < n - 1 - j:
              continue
            dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y])
      return dp[-1][-1]

    return getTopLeft() + getTopRight() + getBottomLeft() - 2 * fruits[-1][-1]
