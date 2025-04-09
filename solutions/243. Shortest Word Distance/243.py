class Solution:
  def shortestDistance(
      self,
      wordsDict: list[str],
      word1: str,
      word2: str,
  ) -> int:
    ans = len(wordsDict)
    index1 = -1  # wordsdict[index1] == word1
    index2 = -1  # wordsdict[index2] == word2

    for i, word in enumerate(wordsDict):
      if word == word1:
        index1 = i
        if index2 != -1:
          ans = min(ans, index1 - index2)
      if word == word2:
        index2 = i
        if index1 != -1:
          ans = min(ans, index2 - index1)

    return ans
