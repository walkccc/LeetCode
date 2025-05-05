class Solution:
  def totalHammingDistance(self, nums: list[int]) -> int:
    MAX_BIT = 30
    ans = 0

    for i in range(MAX_BIT):
      ones = sum(num & (1 << i) > 0 for num in nums)
      zeros = len(nums) - ones
      ans += ones * zeros

    return ans
