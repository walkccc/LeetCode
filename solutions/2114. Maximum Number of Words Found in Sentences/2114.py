class Solution:
  def mostWordsFound(self, sentences: List[str]) -> int:
    return max(s.count(' ') for s in sentences) + 1
