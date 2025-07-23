class Solution:
  def mostWordsFound(self, sentences: list[str]) -> int:
    return max(s.count(' ') for s in sentences) + 1
