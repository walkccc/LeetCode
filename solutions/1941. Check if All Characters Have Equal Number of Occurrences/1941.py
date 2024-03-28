class Solution:
  def areOccurrencesEqual(self, s: str) -> bool:
    return len(set(collections.Counter(s).values())) == 1
