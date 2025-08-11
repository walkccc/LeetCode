class Solution:
  def sumOfGoodSubsequences(self, nums: list[int]) -> int:
    MOD = 10**9 + 7
    maxNum = max(nums)
    # endsIn[i] := the number of good subsequences ending in i
    endsIn = [0] * (maxNum + 2)
    # dp[i] := the sum of good subsequences ending in i
    dp = [0] * (maxNum + 2)

    for num in nums:
      seqsToAppend = 1 + endsIn[num - 1] + endsIn[num + 1]
      dp[num] = (seqsToAppend * num +
                 (dp[num] + dp[num - 1] + dp[num + 1])) % MOD
      endsIn[num] += seqsToAppend % MOD

    return sum(dp) % MOD
