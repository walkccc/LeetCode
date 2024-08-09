class Solution:
  def countQuadruplets(self, nums: List[int]) -> int:
    ans = 0
    # dp[j] := the number of triplets (i, j, k) where i < j < k and nums[i] < nums[k] <
    # nums[j]. Keep this information for l to use later.
    dp = [0] * len(nums)

    # k can be treated as l.
    for k in range(2, len(nums)):
      numLessThanK = 0
      # j can be treated as i.
      for j in range(k):
        if nums[j] < nums[k]:
          numLessThanK += 1  # nums[i] < nums[k]
          # nums[j] < nums[l], so we should add dp[j] since we find a new
          # quadruplets for (i, j, k, l).
          ans += dp[j]
        elif nums[j] > nums[k]:
          dp[j] += numLessThanK

    return ans
