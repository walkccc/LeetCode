class Solution:
  def rearrangeCharacters(self, s: str, target: str) -> int:
    countS = collections.Counter(s)
    countT = collections.Counter(target)
    return min(countS[c] // countT[c] for c in target)
