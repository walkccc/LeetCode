class Solution:
  def maxSum(self, nums: list[int], k: int, m: int) -> int:
    INF = 20_000_000
    n = len(nums)
    prefix = list(itertools.accumulate(nums, initial=0))

    # dp[i][ongoing][r] := the maximum sum of nums[i:], with `ongoing`
    # indicating if a subarray is currently being extended (1) or not (0),
    # and `r` segments left to choose
    dp = [[[-INF] * (k + 1) for _ in range(2)] for _ in range(n + 1)]

    # Base case: At the end of the array, if no segments are left, score is 0
    dp[n][0][0] = dp[n][1][0] = 0

    for i in range(n - 1, -1, -1):
      for rem in range(k + 1):
        # When no subarray is ongoing:
        # 1. Skip nums[i]
        dp[i][0][rem] = dp[i + 1][0][rem]
        # 2. Start a new segment of length m (only if rem > 0 and there're enough elements)
        if rem > 0 and i + m <= n:
          dp[i][0][rem] = max(
              dp[i][0][rem],
              dp[i + m][1][rem - 1] + (prefix[i + m] - prefix[i]))
        # When a subarray is ongoing:
        # 1. End the current subarray (transition to state 0, same index i)
        # 2. Extend the current subarray by picking nums[i] and move to i + 1
        dp[i][1][rem] = max(dp[i][0][rem], dp[i + 1][1][rem] + nums[i])

    return dp[0][0][k]
