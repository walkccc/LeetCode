class Solution:
  def separateDigits(self, nums: list[int]) -> list[int]:
    return [int(c) for num in nums for c in str(num)]
