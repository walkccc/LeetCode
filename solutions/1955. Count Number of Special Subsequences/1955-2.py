class Solution:
  def countSpecialSubsequences(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    # dp[i][j] := # of increasing subseqs of nums[:i] ending at j
    dp = [[0] * 3 for _ in range(n)]

    if nums[0] == 0:
      dp[0][0] = 1

    for i in range(1, n):
      for endingAt in range(3):
        dp[i][endingAt] = dp[i - 1][endingAt]

      if nums[i] == 0:
        # prev ending at 0 + prev ending at 0 + [0] + start new from this 0
        dp[i][0] = dp[i - 1][0] * 2 + 1
      elif nums[i] == 1:
        # prev ending at 1 + prev ending at 1 + [1] + prev ending at 0 + [1]
        dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0]
      else:  # nums[i] == 2
        # prev ending at 2 + prev ending at 2 + [2] + prev ending at 1 + [2]
        dp[i][2] = dp[i - 1][2] * 2 + dp[i - 1][1]

      for endingAt in range(3):
        dp[i][endingAt] %= kMod

    return dp[-1][2]
