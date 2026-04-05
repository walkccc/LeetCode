class Solution:
  def findPermutationDifference(self, s: str, t: str) -> int:
    indices = {c: i for i, c in enumerate(s)}
    return sum([abs(indices[c] - i) for i, c in enumerate(t)])
