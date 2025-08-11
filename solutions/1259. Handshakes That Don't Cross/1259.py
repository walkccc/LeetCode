class Solution:
  def numberOfWays(self, numPeople: int) -> int:
    MOD = 1_000_000_007
    # dp[i] := the number of ways i handshakes could occure s.t. none of the
    # handshakes cross
    dp = [1] + [0] * (numPeople // 2)

    for i in range(1, numPeople // 2 + 1):
      for j in range(i):
        dp[i] += dp[j] * dp[i - 1 - j]
        dp[i] %= MOD

    return dp[numPeople // 2]
