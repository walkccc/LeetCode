class Solution:
  def commonChars(self, words: list[str]) -> list[str]:
    return functools.reduce(lambda a, b: a & b,
                            map(collections.Counter, words)).elements()
