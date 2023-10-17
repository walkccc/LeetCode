class Solution:
  def numberOfWays(self, numPeople: int) -> int:
    kMod = 1_000_000_007
    # dp[i] := # of ways i handshakes pair w//o crossing
    dp = [1] + [0] * (numPeople // 2)

    for i in range(1, numPeople // 2 + 1):
      for j in range(i):
        dp[i] += dp[j] * dp[i - 1 - j]
        dp[i] %= kMod

    return dp[numPeople // 2]
