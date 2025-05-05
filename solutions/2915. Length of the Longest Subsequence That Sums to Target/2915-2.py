class Solution:
  def lengthOfLongestSubsequence(self, nums: list[int], target: int) -> int:
    # dp[i] := the maximum length of any subsequence of numbers so far that
    # sum to j
    dp = [0] * (target + 1)

    for num in nums:
      for i in range(target, num - 1, -1):
        if i == num or dp[i - num] > 0:
          dp[i] = max(dp[i], 1 + dp[i - num])

    return dp[target] if dp[target] > 0 else -1
