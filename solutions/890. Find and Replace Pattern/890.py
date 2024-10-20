class Solution:
  def findAndReplacePattern(self, words: list[str], pattern: str) -> list[str]:
    def isIsomorphic(w: str, p: str) -> bool:
      return [*map(w.index, w)] == [*map(p.index, p)]
    return [word for word in words if isIsomorphic(word, pattern)]
