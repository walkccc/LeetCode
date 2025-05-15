class Solution:
  def longestCommonPrefix(self, s: str, t: str) -> int:
    i = 0  # s's index
    j = 0  # t's index
    canSkip = True

    while i < len(s) and j < len(t):
      if s[i] == t[j]:
        i += 1
        j += 1
      elif canSkip:
        i += 1
        canSkip = False
      else:
        return j

    return j
