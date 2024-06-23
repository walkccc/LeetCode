class Solution:
  def longestRepeatingSubstring(self, s: str) -> int:
    n = len(s)
    ans = 0
    # dp[i][j] := the number of repeating characters of s[0..i) and s[0..j)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
      for j in range(i + 1, n + 1):
        if s[i - 1] == s[j - 1]:
          dp[i][j] = 1 + dp[i - 1][j - 1]
          ans = max(ans, dp[i][j])

    return ans
