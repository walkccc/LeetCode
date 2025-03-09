class Solution:
  def possibleStringCount(self, word: str) -> int:
    return 1 + sum(a == b
                   for a, b in itertools.pairwise(word))
