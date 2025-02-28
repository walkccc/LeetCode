class Solution:
  def countSpecialSubsequences(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    # dp[j] := the number of increasing subsequences of the numbers so far that
    # end in j
    dp = [0] * 3

    if nums[0] == 0:
      dp[0] = 1

    for i in range(1, n):
      if nums[i] == 0:
        dp[0] = dp[0] * 2 + 1
      elif nums[i] == 1:
        dp[1] = dp[1] * 2 + dp[0]
      else:  # nums[i] == 2
        dp[2] = dp[2] * 2 + dp[1]

      for ending in range(3):
        dp[ending] %= kMod

    return dp[2]
