class Solution:
  def maximumOddBinaryNumber(self, s: str) -> str:
    return '1' * (s.count('1') - 1) + '0' * s.count('0') + '1'
