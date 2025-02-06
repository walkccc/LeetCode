class Solution:
  def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
    wordSet = set(wordDict)

    @functools.lru_cache(None)
    def wordBreak(s: str) -> list[str]:
      ans = []

      # 1 <= len(prefix) < len(s)
      for i in range(1, len(s)):
        prefix = s[0:i]
        suffix = s[i:]
        if prefix in wordSet:
          for word in wordBreak(suffix):
            ans.append(prefix + ' ' + word)

      # `wordSet` contains the whole string s, so don't add any space.
      if s in wordSet:
        ans.append(s)

      return ans

    return wordBreak(s)
