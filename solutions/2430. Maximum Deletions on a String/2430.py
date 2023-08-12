class Solution:
  def deleteString(self, s: str) -> int:
    n = len(s)
    # lcs[i][j] := # of the same characters of s[i:] and s[j:]
    lcs = [[0] * (n + 1) for _ in range(n + 1)]
    # dp[i] := max # of operations needed to delete s[i:]
    dp = [1] * n

    for i in reversed(range(n)):
      for j in range(i + 1, n):
        if s[i] == s[j]:
          lcs[i][j] = lcs[i + 1][j + 1] + 1
        if lcs[i][j] >= j - i:
          dp[i] = max(dp[i], dp[j] + 1)

    return dp[0]
