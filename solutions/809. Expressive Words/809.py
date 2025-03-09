class Solution:
  def expressiveWords(self, s: str, words: list[str]) -> int:
    def isStretchy(word: str) -> bool:
      n = len(s)
      m = len(word)

      j = 0
      for i in range(n):
        if j < m and s[i] == word[j]:
          j += 1
        elif i > 1 and s[i] == s[i - 1] == s[i - 2]:
          continue
        elif 0 < i < n - 1 and s[i - 1] == s[i] == s[i + 1]:
          continue
        else:
          return False

      return j == m

    return sum(isStretchy(word) for word in words)
