class Solution:
  def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
    # dp[i] := max length of any subseq of nums so far that sums to j
    dp = [0] * (target + 1)

    for num in nums:
      for i in range(target, num - 1, -1):
        if i == num or dp[i - num] > 0:
          dp[i] = max(dp[i], 1 + dp[i - num])

    return dp[target] if dp[target] > 0 else -1
