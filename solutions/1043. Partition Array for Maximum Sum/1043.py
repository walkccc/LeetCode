class Solution:
  def maxSumAfterPartitioning(self, arr: list[int], k: int) -> int:
    n = len(arr)
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
      mx = -math.inf
      for j in range(1, min(i, k) + 1):
        mx = max(mx, arr[i - j])
        dp[i] = max(dp[i], dp[i - j] + mx * j)

    return dp[n]
