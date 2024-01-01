class Solution:
  def sumOfDigits(self, nums: List[int]) -> int:
    return sum(int(d) for d in str(min(nums))) & 1 ^ 1
