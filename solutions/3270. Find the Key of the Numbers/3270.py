class Solution:
  def generateKey(self, num1: int, num2: int, num3: int) -> int:
    return int(''.join(min(a, b, c)
                       for a, b, c in zip(str(num1).zfill(4),
                                          str(num2).zfill(4),
                                          str(num3).zfill(4))))
