class Solution:
  def numTilings(self, N: int) -> int:
    kMod = int(1e9 + 7)
    dp = [0, 1, 2, 5] + [0] * 997

    for i in range(4, N + 1):
      dp[i] = 2 * dp[i - 1] + dp[i - 3]

    return dp[N] % kMod
