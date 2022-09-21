class Solution:
  def longestStrChain(self, words: List[str]) -> int:
    wordsSet = set(words)

    # dp(s) := longest chain where s is the last word
    @functools.lru_cache(None)
    def dp(s: str) -> int:
      ans = 1
      for i in range(len(s)):
        pred = s[:i] + s[i + 1:]
        if pred in wordsSet:
          ans = max(ans, dp(pred) + 1)
      return ans

    return max(dp(word) for word in words)
