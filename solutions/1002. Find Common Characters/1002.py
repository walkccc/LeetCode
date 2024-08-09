class Solution:
  def commonChars(self, words: List[str]) -> List[str]:
    return functools.reduce(lambda a, b: a & b,
                            map(collections.Counter, words)).elements()
