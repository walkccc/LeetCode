class Solution:
  def scoreOfString(self, s: str) -> int:
    return sum(abs(ord(a) - ord(b))
               for a, b in itertools.pairwise(s))
