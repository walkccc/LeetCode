class Solution:
  def wordBreak(self, s: str, wordDict: list[str]) -> bool:
    wordSet = set(wordDict)

    @functools.lru_cache(None)
    def wordBreak(s: str) -> bool:
      """Returns True if s can be segmented."""
      if s in wordSet:
        return True
      return any(s[:i] in wordSet and wordBreak(s[i:]) for i in range(len(s)))

    return wordBreak(s)
