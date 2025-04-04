class Solution:
  def minMoves(self, nums: list[int]) -> int:
    mn = min(nums)
    return sum(num - mn for num in nums)
