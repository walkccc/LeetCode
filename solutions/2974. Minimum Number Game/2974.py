class Solution:
  def numberGame(self, nums: list[int]) -> list[int]:
    nums.sort()
    return [nums[i + 1] if i % 2 == 0
            else nums[i - 1]
            for i in range(len(nums))]
