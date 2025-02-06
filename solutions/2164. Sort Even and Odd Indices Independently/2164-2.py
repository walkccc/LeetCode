class Solution:
  def sortEvenOdd(self, nums: list[int]) -> list[int]:
    nums[::2] = sorted(nums[::2])
    nums[1::2] = sorted(nums[1::2])[::-1]
    return nums
