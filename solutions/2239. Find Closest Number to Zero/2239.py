class Solution:
  def findClosestNumber(self, nums: list[int]) -> int:
    nums.sort(key=lambda x: (abs(x), -x))
    return nums[0]
