class Solution:
  def longestArithSeqLength(self, nums: List[int]) -> int:
    n = len(nums)
    ans = 0
    # dp[i][k] := length of the longest arithmetic subseq ofnums
    # nums[0..i] with k = diff + 500
    dp = [[0] * 1001 for _ in range(n)]

    for i in range(n):
      for j in range(i):
        k = nums[i] - nums[j] + 500
        dp[i][k] = max(2, dp[j][k] + 1)
        ans = max(ans, dp[i][k])

    return ans
