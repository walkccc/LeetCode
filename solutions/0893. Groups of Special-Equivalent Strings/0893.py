class Solution:
  def numSpecialEquivGroups(self, A: List[str]) -> int:
    return len({''.join(sorted(s[::2])) + ''.join(sorted(s[1::2])) for s in A})
