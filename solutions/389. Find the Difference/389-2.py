class Solution:
  def findTheDifference(self, s: str, t: str) -> str:
    count = collections.Counter(s)

    for c in t:
      if count[c] == 0:
        return c
      count[c] -= 1
