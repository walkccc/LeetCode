class Solution:
  def brokenCalc(self, X: int, Y: int) -> int:
    ops = 0

    while X < Y:
      if Y % 2 == 0:
        Y //= 2
      else:
        Y += 1
      ops += 1

    return ops + X - Y
