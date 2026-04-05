class Solution:
  def encode(self, s: str) -> str:
    n = len(s)
    # dp[i][j] := the shortest encoded string of s[i..j]
    dp = [[''] * n for _ in range(n)]

    for d in range(n):
      for i in range(n - d):
        j = i + d
        curr = s[i:j + 1]
        dp[i][j] = curr

        if len(dp[i][j]) < 5:
          continue

        # Try all the possible partitions.
        for k in range(i, j):
          if len(dp[i][k]) + len(dp[k + 1][j]) < len(dp[i][j]):
            dp[i][j] = dp[i][k] + dp[k + 1][j]

        # Try to compress the string.
        # e.g. s = aabaabaab -> 3[aab]
        for k in range(i, j):
          pattern = s[i:k + 1]
          if len(curr) % len(pattern) == 0 and pattern * (len(curr) //
                                                          len(pattern)) == curr:
            candidate = f"{len(curr) // len(pattern)}[{dp[i][k]}]"
            if len(candidate) < len(dp[i][j]):
              dp[i][j] = candidate

    return dp[0][n - 1]
