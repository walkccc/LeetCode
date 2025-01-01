class Solution:
  def validSequence(self, word1: str, word2: str) -> list[int]:
    ans = []
    # last[j] := the index i of the last occurrence in word1, where
    # word1[i] == word2[j]
    last = [-1] * len(word2)

    i = len(word1) - 1
    j = len(word2) - 1
    while i >= 0 and j >= 0:
      if word1[i] == word2[j]:
        last[j] = i
        j -= 1
      i -= 1

    canSkip = True
    j = 0
    for i, c in enumerate(word1):
      if j == len(word2):
        break
      if c == word2[j]:
        ans.append(i)
        j += 1
      elif canSkip and (j == len(word2) - 1 or i < last[j + 1]):
        canSkip = False
        ans.append(i)
        j += 1

    return ans if j == len(word2) else []
