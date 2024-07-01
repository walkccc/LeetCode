class Solution:
  def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
    minStep = max(abs(sx - fx), abs(sy - fy))
    return t != 1 if minStep == 0 else minStep <= t
