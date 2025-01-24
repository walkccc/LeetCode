class Solution:
  def rearrangeArray(self, nums: list[int]) -> list[int]:
    nums.sort()
    for i in range(1, len(nums), 2):
      nums[i], nums[i - 1] = nums[i - 1], nums[i]
    return nums
