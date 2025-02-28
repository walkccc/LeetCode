class Solution:
  def maximumSumScore(self, nums: list[int]) -> int:
    ans = -math.inf
    prefix = 0
    summ = sum(nums)

    for num in nums:
      prefix += num
      ans = max(ans, prefix, summ - prefix + num)

    return ans
