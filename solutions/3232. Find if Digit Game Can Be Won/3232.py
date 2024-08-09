class Solution:
  def canAliceWin(self, nums: List[int]) -> bool:
    return sum(num if num < 10 else -num for num in nums) != 0
