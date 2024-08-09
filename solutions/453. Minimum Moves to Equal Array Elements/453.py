class Solution:
  def minMoves(self, nums: List[int]) -> int:
    mn = min(nums)
    return sum(num - mn for num in nums)
