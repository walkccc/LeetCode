class Solution:
  # Similar to 516. Longest Palindromic Subsequence
  def longestPalindromicSubsequence(self, s: str, k: int) -> int:
    @functools.lru_cache(None)
    def dp(i: int, j: int, op: int) -> int:
      """Returns the length of LPS(s[i..j]) with at most `op` operations."""
      if i > j:
        return 0
      if i == j:
        return 1
      if s[i] == s[j]:
        return 2 + dp(i + 1, j - 1, op)
      res = max(dp(i + 1, j, op), dp(i, j - 1, op))
      cost = self._getCost(s[i], s[j])
      if cost <= op:
        res = max(res, 2 + dp(i + 1, j - 1, op - cost))
      return res

    return dp(0, len(s) - 1, k)

  def _getCost(self, a: str, b: str) -> int:
    dist = abs(ord(a) - ord(b))
    return min(dist, 26 - dist)
