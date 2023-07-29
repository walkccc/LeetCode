class Solution:
  def separateDigits(self, nums: List[int]) -> List[int]:
    return [int(c) for num in nums for c in str(num)]
