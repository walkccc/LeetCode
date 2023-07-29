class Solution:
  def isLongPressedName(self, name: str, typed: str) -> bool:
    i = 0

    for j, t in enumerate(typed):
      if i < len(name) and name[i] == t:
        i += 1
      elif j == 0 or t != typed[j - 1]:
        return False

    return i == len(name)
