class Solution:
  def countSpecialSubsequences(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    # dp[i][j] := the number of increasing subsequences of the first i numbers
    # that end in j
    dp = [[0] * 3 for _ in range(n)]

    if nums[0] == 0:
      dp[0][0] = 1

    for i in range(1, n):
      for ending in range(3):
        dp[i][ending] = dp[i - 1][ending]

      if nums[i] == 0:
        # 1. The number of the previous subsequences that end in 0.
        # 2. Append a 0 to the previous subsequences that end in 0.
        # 3. Start a new subsequence from this 0.
        dp[i][0] = dp[i - 1][0] * 2 + 1
      elif nums[i] == 1:
        # 1. The number of the previous subsequences that end in 1.
        # 2. Append a 1 to the previous subsequences that end in 1.
        # 3. Append a 1 to the previous subsequences that end in 0.
        dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0]
      else:  # nums[i] == 2
        # 1. The number of the previous subsequences that end in 2.
        # 2. Append a 2 to the previous subsequences that end in 2.
        # 3. Append a 2 to the previous subsequences that end in 1.
        dp[i][2] = dp[i - 1][2] * 2 + dp[i - 1][1]

      for ending in range(3):
        dp[i][ending] %= kMod

    return dp[-1][2]
