class Solution:
  def largestSumAfterKNegations(self, nums: list[int], k: int) -> int:
    nums.sort()

    for i, num in enumerate(nums):
      if num > 0 or k == 0:
        break
      nums[i] = -num
      k -= 1

    return sum(nums) - (k % 2) * min(nums) * 2
