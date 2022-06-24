class Solution:
  def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
    n = len(jobDifficulty)
    if d > n:
      return -1

    # dp[i][k] := min difficulty to schedule the first i jobs in k days
    dp = [[math.inf] * (d + 1) for _ in range(n + 1)]
    dp[0][0] = 0

    for i in range(1, n + 1):
      for k in range(1, d + 1):
        maxDifficulty = 0  # max(job[j + 1..i])
        for j in range(i - 1, k - 2, -1):  # 1-based
          # 0-based
          maxDifficulty = max(maxDifficulty, jobDifficulty[j])
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + maxDifficulty)

    return dp[n][d]
