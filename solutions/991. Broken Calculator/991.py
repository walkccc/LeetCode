class Solution:
  def brokenCalc(self, startValue: int, target: int) -> int:
    ops = 0

    while startValue < target:
      if target % 2 == 0:
        target //= 2
      else:
        target += 1
      ops += 1

    return ops + startValue - target
