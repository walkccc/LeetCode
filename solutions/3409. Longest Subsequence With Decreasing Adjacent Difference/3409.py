class Solution:
  def longestSubsequence(self, nums: list[int]) -> int:
    mx = max(nums)
    # dp[num][diff] := the length of the longest subsequence ending in `num`
    # s.t. the last absolute difference between consecutive elements is `diff`
    dp = [[0] * (mx + 1) for _ in range(mx + 1)]

    for num in nums:
      for prev in range(1, mx + 1):
        diff = abs(num - prev)
        dp[num][diff] = max(dp[num][diff], dp[prev][diff] + 1)
      # dp[num][diff] := max(dp[num][j]) for j >= diff
      for j in range(mx - 1, -1, -1):
        dp[num][j] = max(dp[num][j], dp[num][j + 1])

    return max(map(max, dp))
