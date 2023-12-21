class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:
    @functools.lru_cache(None)
    def dp(i: int, j: int) -> int:
      """Returns the length of LPS(s[i..j])."""
      if i > j:
        return 0
      if i == j:
        return 1
      if s[i] == s[j]:
        return 2 + dp(i + 1, j - 1)
      return max(dp(i + 1, j), dp(i, j - 1))

    return dp(0, len(s) - 1)
