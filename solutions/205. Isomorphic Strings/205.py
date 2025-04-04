class Solution:
  def isIsomorphic(self, s: str, t: str) -> bool:
    return [*map(s.index, s)] == [*map(t.index, t)]
