class Solution:
  def maximizeSum(self, nums: list[int], k: int) -> int:
    return max(nums) * k + k * (k - 1) // 2
