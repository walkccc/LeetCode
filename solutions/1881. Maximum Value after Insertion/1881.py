class Solution:
  def maxValue(self, n: str, x: int) -> str:
    isNegative = n[0] == '-'

    for i, c in enumerate(n):
      if not isNegative and int(c) < x or isNegative and int(c) > x:
        return n[:i] + str(x) + n[i:]

    return n + str(x)
