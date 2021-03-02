class Solution:
  def isNumber(self, s: str) -> bool:
    s = s.strip()
    if not s:
      return False

    seenNum = False
    seenDot = False
    seenE = False

    for i, c in enumerate(s):
      if c == '.':
        if seenDot or seenE:
          return False
        seenDot = True
      elif c == 'e':
        if seenE or not seenNum:
          return False
        seenE = True
        seenNum = False
      elif c in '+-':
        if i > 0 and s[i - 1] != 'e':
          return False
        seenNum = False
      else:
        if not c.isdigit():
          return False
        seenNum = True

    return seenNum
