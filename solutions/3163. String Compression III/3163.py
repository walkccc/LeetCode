class Solution:
  def compressedString(self, word: str) -> str:
    n = len(word)
    ans = []
    i = 0
    j = 0

    while i < n:
      count = 0
      while j < n and word[j] == word[i] and count < 9:
        j += 1
        count += 1
      ans.append(str(count) + word[i])
      i = j

    return ''.join(ans)
