class Solution:
  def maxScore(self, a: list[int], b: list[int]) -> int:
    n = len(b)
    # dp[i][j] := the maximum score by selecting 4 - i numbers from b[j..n - 1]
    # using the corresponding numbers from a[i..3]
    dp = [[0] * (n + 1) for _ in range(5)]

    # Run out of numbers in b but still need to select numbers from a.
    for i in range(4):
      dp[i][n] = -math.inf

    for i in reversed(range(4)):
      for j in reversed(range(n)):
        # Skip b[j] or pair a[i] with b[j].
        dp[i][j] = max(dp[i][j + 1], a[i] * b[j] + dp[i + 1][j + 1])

    return -1 if dp[0][0] == -math.inf else dp[0][0]
