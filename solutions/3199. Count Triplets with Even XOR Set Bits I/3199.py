class Solution:
  def tripletCount(self, a: List[int], b: List[int], c: List[int]) -> int:
    evenA, oddA = self._getEvenOddBitCount(a)
    evenB, oddB = self._getEvenOddBitCount(b)
    evenC, oddC = self._getEvenOddBitCount(c)
    return evenA * oddB * oddC + oddA * evenB * oddC + oddA * oddB * evenC + evenA * evenB * evenC

  def _getEvenOddBitCount(self, nums: List[int]) -> Tuple[int, int]:
    """
    Returns the count of numbers in the `nums` arrays that have even number of
    ones and odd number of ones in their binary representation.
    """
    even = sum(num.bit_count() % 2 == 0 for num in nums)
    return (even, len(nums) - even)
