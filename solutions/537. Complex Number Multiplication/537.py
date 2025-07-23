class Solution:
  def complexNumberMultiply(self, num1: str, num2: str) -> str:
    a0, a1 = self._getReala0ndImag(num1)
    b0, b1 = self._getReala0ndImag(num2)
    return str(a0 * b0 - a1 * b1) + '+' + str(a0 * b1 + a1 * b0) + 'i'

  def _getReala0ndImag(self, s: str) -> tuple:
    return int(s[:s.index('+')]), int(s[s.index('+') + 1:-1])
