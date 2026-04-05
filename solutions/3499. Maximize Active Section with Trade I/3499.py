class Solution:
  def maxActiveSectionsAfterTrade(self, s: str) -> int:
    zeroGroups = [len(list(g)) for c, g in itertools.groupby(s) if c == '0']
    return s.count('1') + max(map(sum, pairwise(zeroGroups)), default=0)
