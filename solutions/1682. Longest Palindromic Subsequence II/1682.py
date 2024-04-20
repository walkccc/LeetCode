class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:
    n = len(s)

    @functools.lru_cache(None)
    def dp(i: int, j: int, k: int) -> int:
      """
      Returns the length of LPS(s[i..j]), where the previous letter is
      ('a' + k).
      """
      if i >= j:
        return 0
      if s[i] == s[j] and s[i] != chr(ord('a') + k):
        return dp(i + 1, j - 1, ord(s[i]) - ord('a')) + 2
      return max(dp(i + 1, j, k), dp(i, j - 1, k))

    return dp(0, n - 1, 26)
