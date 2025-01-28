class Solution:
  def minElement(self, nums: list[int]) -> int:
    return min(sum(map(int, str(num))) for num in nums)
