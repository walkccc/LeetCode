class Solution:
  def splitArray(self, nums: List[int], m: int) -> int:
    n = len(nums)
    # dp[i][k] := min of largest sum to split first i nums into k groups
    dp = [[math.inf] * (m + 1) for _ in range(n + 1)]
    prefix = [0] + list(itertools.accumulate(nums))

    for i in range(1, n + 1):
      dp[i][1] = prefix[i]

    for k in range(2, m + 1):
      for i in range(k, n + 1):
        for j in range(k - 1, i):
          dp[i][k] = min(dp[i][k], max(dp[j][k - 1], prefix[i] - prefix[j]))

    return dp[n][m]
