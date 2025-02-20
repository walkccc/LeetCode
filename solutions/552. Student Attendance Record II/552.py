class Solution:
  def checkRecord(self, n: int) -> int:
    kMod = 1_000_000_007
    # dp[i][j] := the length so far with i A's and the last letters are j L's
    dp = [[0] * 3 for _ in range(2)]
    dp[0][0] = 1

    for _ in range(n):
      prev = [A[:] for A in dp]

      # Append a P.
      dp[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % kMod

      # Append an L.
      dp[0][1] = prev[0][0]

      # Append an L.
      dp[0][2] = prev[0][1]

      # Append an A or append a P.
      dp[1][0] = (prev[0][0] + prev[0][1] + prev[0][2] +
                  prev[1][0] + prev[1][1] + prev[1][2]) % kMod

      # Append an L.
      dp[1][1] = prev[1][0]

      # Append an L.
      dp[1][2] = prev[1][1]

    return (sum(dp[0]) + sum(dp[1])) % kMod
