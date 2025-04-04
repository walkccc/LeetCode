class Solution:
  def minOperations(self, initial: str, target: str) -> int:
    m = len(initial)
    n = len(target)
    # dp[i][j] := the length of LCS(initial[0..i), target[0..j))
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
      for j in range(1, n + 1):
        if initial[i - 1] == target[j - 1]:
          dp[i][j] = 1 + dp[i - 1][j - 1]

    return m + n - 2 * max(map(max, dp))
