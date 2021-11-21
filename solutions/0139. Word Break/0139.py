class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    wordSet = set(wordDict)

    @lru_cache(None)
    def wordBreak(s: str) -> bool:
      if s in wordSet:
        return True

      # 1 <= prefix.length() < s.length()
      for i in range(1, len(s)):
        prefix = s[0:i]
        suffix = s[i:]
        if prefix in wordSet and wordBreak(suffix):
          return True

      return False

    return wordBreak(s)
