class Solution:
  def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
    n = len(arr)
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
      maxi = -math.inf
      for j in range(1, min(i, k) + 1):
        maxi = max(maxi, arr[i - j])
        dp[i] = max(dp[i], dp[i - j] + maxi * j)

    return dp[n]
