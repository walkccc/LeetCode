class Solution:
  def sumOfPower(self, nums: list[int], k: int) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    # dp[i][j] := the number of subsequences in nums[0..i) that sums to k
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1

    for i in range(1, n + 1):
      num = nums[i - 1]
      for j in range(k + 1):
        if j < num:
          # 1. Exclude nums[i] in the subsequence.
          # 2. Include nums[i] in the subsequence and skip it.
          dp[i][j] = (dp[i - 1][j] * 2) % kMod
        else:
          # 1. Exclude nums[i] in the subsequence.
          # 2. Include nums[i] in the subsequence and skip it.
          # 3. Include nums[i] in the subsequence and pick it.
          dp[i][j] = (dp[i - 1][j] * 2 + dp[i - 1][j - num]) % kMod

    return dp[n][k]
