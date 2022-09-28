class Solution:
  def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
    def isIsomorphic(w: str, p: str) -> bool:
      return [*map(w.index, w)] == [*map(p.index, p)]
    return [word for word in words if isIsomorphic(word, pattern)]
