class Solution:
  def expressiveWords(self, S: str, words: List[str]) -> int:
    def isStretchy(word: str) -> bool:
      n = len(S)
      m = len(word)

      j = 0
      for i in range(n):
        if j < m and S[i] == word[j]:
          j += 1
        elif i > 1 and S[i] == S[i - 1] == S[i - 2]:
          continue
        elif 0 < i < n - 1 and S[i - 1] == S[i] == S[i + 1]:
          continue
        else:
          return False

      return j == m

    return sum(isStretchy(word) for word in words)
