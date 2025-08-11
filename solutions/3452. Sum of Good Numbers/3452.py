class Solution:
  def sumOfGoodNumbers(self, nums: list[int], k: int) -> int:
    return sum(num for i, num in enumerate(nums)
               if (i - k < 0 or num > nums[i - k])
               and (i + k >= len(nums) or num > nums[i + k]))
