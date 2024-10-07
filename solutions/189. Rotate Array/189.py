class Solution:
  def rotate(self, nums: list[int], k: int) -> None:
    k %= len(nums)
    self.reverse(nums, 0, len(nums) - 1)
    self.reverse(nums, 0, k - 1)
    self.reverse(nums, k, len(nums) - 1)

  def reverse(self, nums: list[int], l: int, r: int) -> None:
    while l < r:
      nums[l], nums[r] = nums[r], nums[l]
      l += 1
      r -= 1
