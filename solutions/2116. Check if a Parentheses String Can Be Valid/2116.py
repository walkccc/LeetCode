class Solution:
  def canBeValid(self, s: str, locked: str) -> bool:
    if len(s) % 2 == 1:
      return False

    def check(s: str, locked: str, isForward: bool) -> bool:
      changeable = 0
      l = 0
      r = 0

      for c, lock in zip(s, locked):
        if lock == '0':
          changeable += 1
        elif c == '(':
          l += 1
        else:  # c == ')'
          r += 1
        if isForward and changeable + l - r < 0:
          return False
        if not isForward and changeable + r - l < 0:
          return False

      return True

    return check(s, locked, True) and check(s[::-1], locked[::-1], False)
