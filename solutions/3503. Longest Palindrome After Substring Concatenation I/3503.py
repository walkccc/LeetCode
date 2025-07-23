class Solution:
  def longestPalindrome(self, s: str, t: str) -> int:
    m = len(s)
    n = len(t)
    suffix = self._getPalindromeLengths(s, True)
    prefix = self._getPalindromeLengths(t, False)
    ans = max(max(suffix), max(prefix))
    # dp[i][j] := the longest length of palindrome starting in s[i] and ending
    # in t[j]
    dp = [[0] * n for _ in range(m)]

    for i in range(m):
      for j in range(n - 1, -1, -1):
        if s[i] == t[j]:
          dp[i][j] = 2 + (dp[i - 1][j + 1] if i > 0 and j < n - 1 else 0)
          extend = max(suffix[i + 1] if i + 1 < m else 0,
                       prefix[j - 1] if j > 0 else 0)
          ans = max(ans, dp[i][j] + extend)

    return ans

  def _getPalindromeLengths(self, s: str, isSuffix: bool) -> list[int]:
    n = len(s)
    # dp[i][j] := True if s[i..j] is a palindrome
    dp = [[False] * n for _ in range(n)]
    # lengths[i] := length of longest palindrome in s[i..n - 1]
    lengths = [0] * n
    for i in range(n - 1, -1, -1):
      for j in range(i, n):
        if s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1]):
          dp[i][j] = True
          index = i if isSuffix else j
          lengths[index] = max(lengths[index], j - i + 1)
    return lengths
