class Solution:
  def maxPoints(self, points: List[List[int]]) -> int:
    n = len(points[0])
    # dp[j] := max # points you can have if points[i][j] is the most recent cell you picked
    dp = [0] * n

    for row in points:
      leftToRight = [0] * n
      runningMax = 0
      for j in range(n):
        runningMax = max(runningMax - 1, dp[j])
        leftToRight[j] = runningMax

      rightToLeft = [0] * n
      runningMax = 0
      for j in range(n - 1, - 1, -1):
        runningMax = max(runningMax - 1, dp[j])
        rightToLeft[j] = runningMax

      for j in range(n):
        dp[j] = max(leftToRight[j], rightToLeft[j]) + row[j]

    return max(dp)
