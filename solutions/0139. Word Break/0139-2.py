class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    wordSet = set(wordDict)

    @functools.lru_cache(None)
    def wordBreak(i: int) -> bool:
      """Returns True if s[i..n) can be segmented."""
      if i == len(s):
        return True
      return any(s[i:j] in wordSet and wordBreak(j) for j in range(i + 1, len(s) + 1))

    return wordBreak(0)
