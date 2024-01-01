class Solution:
  def splitArray(self, nums: List[int], k: int) -> int:
    n = len(nums)
    # dp[i][k] := the minimum of the maximum sum to split the first i nums into
    # k groups
    dp = [[math.inf] * (k + 1) for _ in range(n + 1)]
    prefix = [0] + list(itertools.accumulate(nums))

    for i in range(1, n + 1):
      dp[i][1] = prefix[i]

    for l in range(2, k + 1):
      for i in range(l, n + 1):
        for j in range(l - 1, i):
          dp[i][l] = min(dp[i][l], max(dp[j][l - 1], prefix[i] - prefix[j]))

    return dp[n][k]
