class Solution:
  def maxAscendingSum(self, nums: list[int]) -> int:
    ans = 0
    sum = nums[0]

    for i in range(1, len(nums)):
      if nums[i] > nums[i - 1]:
        sum += nums[i]
      else:
        ans = max(ans, sum)
        sum = nums[i]

    return max(ans, sum)
