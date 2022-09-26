class Solution:
  def findTheDifference(self, s: str, t: str) -> str:
    count = Counter(s)

    for i, c in enumerate(t):
      count[c] -= 1
      if count[c] == -1:
        return c
