class Solution:
  def maxValue(self, n: str, x: int) -> str:
    isNegative = n[0] == '-'

    for i, c in enumerate(n):
      if not isNegative and ord(c) - ord('0') < x or isNegative and ord(c) - ord('0') > x:
        return n[:i] + str(x) + n[i:]

    return n + str(x)
