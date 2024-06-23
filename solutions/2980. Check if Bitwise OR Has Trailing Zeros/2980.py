class Solution:
  def hasTrailingZeros(self, nums: List[int]) -> bool:
    return sum(num % 2 == 0 for num in nums) >= 2
