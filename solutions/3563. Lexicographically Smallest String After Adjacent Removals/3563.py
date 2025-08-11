class Solution:
  def lexicographicallySmallestString(self, s: str) -> str:
    n = len(s)
    # dp[i][j]: the lexicographically smallest string by removing adjacent
    # letters from s[i..j)
    dp = [[''] * (n + 1) for _ in range(n + 1)]

    for d in range(1, n + 1):
      for i in range(n - d + 1):
        j = i + d
        # 1. Keep s[i].
        minString = s[i] + dp[i + 1][j]
        # 2. Remove s[i] and s[k] if possible.
        for k in range(i + 1, j):
          if self._isConsecutive(s[i], s[k]) and dp[i + 1][k] == '':
            candidate = dp[k + 1][j]
            if candidate < minString:
              minString = candidate
        dp[i][j] = minString

    return dp[0][n]

  def _isConsecutive(self, a: str, b: str) -> bool:
    return abs(ord(a) - ord(b)) == 1 or abs(ord(a) - ord(b)) == 25
