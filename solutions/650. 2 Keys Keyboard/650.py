class Solution:
  def minSteps(self, n: int) -> int:
    if n <= 1:
      return 0

    # dp[i] := the minimum steps to get i 'A's
    # Copy 'A', then paste 'A' i - 1 times.
    dp = [i for i in range(n + 1)]

    for i in range(2, n + 1):
      for j in range(i // 2, 2, -1):
        if i % j == 0:
          dp[i] = dp[j] + i // j  # Paste dp[j] i / j times.
          break

    return dp[n]
