class Solution:
  def largestMerge(self, word1: str, word2: str) -> str:
    if not word1:
      return word2
    if not word2:
      return word1
    if word1 > word2:
      return word1[0] + self.largestMerge(word1[1:], word2)
    return word2[0] + self.largestMerge(word1, word2[1:])
