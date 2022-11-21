class Solution:
  def rearrangeCharacters(self, s: str, target: str) -> int:
    countS = Counter(s)
    countT = Counter(target)
    return min(countS[c] // countT[c] for c in target)
