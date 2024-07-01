class Solution:
  def minimumOperations(self, nums: List[int]) -> int:
    # dp[i] := the longest non-decreasing subsequence so far with numbers in [1..i]
    dp = [0] * 4

    for num in nums:
      dp[num] += 1  # Append num to the sequence so far.
      dp[2] = max(dp[2], dp[1])
      dp[3] = max(dp[3], dp[2])

    return len(nums) - dp[3]
