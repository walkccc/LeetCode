class Solution:
  def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
    i = 0  # word1's index
    j = 0  # word2's index
    a = 0  # word1[i]'s index
    b = 0  # word2[j]'s index

    while i < len(word1) and j < len(word2):
      if word1[i][a] != word2[j][b]:
        return False
      a += 1
      if a == len(word1[i]):
        i += 1
        a = 0
      b += 1
      if b == len(word2[j]):
        j += 1
        b = 0

    return i == len(word1) and j == len(word2)
