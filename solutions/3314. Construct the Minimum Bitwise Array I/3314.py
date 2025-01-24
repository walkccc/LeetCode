class Solution:
  def minBitwiseArray(self, nums: list[int]) -> list[int]:
    return [-1 if num == 2 else num - self._getLeadingOneOfLastGroupOfOnes(num)
            for num in nums]

  def _getLeadingOneOfLastGroupOfOnes(self, num: int) -> int:
    """
    Returns the leading one of the last group of 1s in the binary
    representation of num. For example, if num = 0b10111, the leading one of
    the last group of 1s is 0b100.
    """
    leadingOne = 1
    while (num & leadingOne) > 0:
      leadingOne <<= 1
    return leadingOne >> 1
