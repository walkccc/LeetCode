class Solution:
  def triangularSum(self, nums: list[int]) -> int:
    for sz in range(len(nums), 0, -1):
      for i in range(sz - 1):
        nums[i] = (nums[i] + nums[i + 1]) % 10
    return nums[0]
