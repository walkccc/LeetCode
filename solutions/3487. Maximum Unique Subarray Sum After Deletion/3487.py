class Solution:
  def maxSum(self, nums: List[int]) -> int:
    mx = max(nums)
    if mx <= 0:
      return mx
    return sum(max(0, num) for num in set(nums))
