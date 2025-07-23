class Solution:
  def smallestIndex(self, nums: List[int]) -> int:
    return next((i
                 for i, num in enumerate(nums)
                 if self._getDigitSum(num) == i), -1)

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
