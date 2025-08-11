class Solution:
  def shortestWordDistance(
      self,
      wordsDict: list[str],
      word1: str,
      word2: str,
  ) -> int:
    isSame = word1 == word2
    ans = math.inf
    # If word1 == word2, index1 is the newest index.
    index1 = len(wordsDict)
    # If word1 == word2, index2 is the previous index.
    index2 = -len(wordsDict)

    for i, word in enumerate(wordsDict):
      if word == word1:
        if isSame:
          index2 = index1
        index1 = i
      elif word == word2:
        index2 = i
      ans = min(ans, abs(index1 - index2))

    return ans
