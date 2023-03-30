class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
      return False

    dict = collections.Counter(s)

    for c in t:
      dict[c] -= 1
      if dict[c] < 0:
        return False

    return True
