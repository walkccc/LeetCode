class Solution:
  def differenceOfSum(self, nums: list[int]) -> int:
    elementSum = sum(nums)
    digitSum = self._getAllDigitSum(nums)
    return abs(elementSum - digitSum)

  def _getAllDigitSum(self, nums: list[int]) -> int:
    return sum(self._getDigitSum(num) for num in nums)

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
