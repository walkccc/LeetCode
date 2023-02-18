class Solution:
  def numTilings(self, N: int) -> int:
    kMod = 1_000_000_007
    dp = [0, 1, 2, 5] + [0] * 997

    for i in range(4, N + 1):
      dp[i] = 2 * dp[i - 1] + dp[i - 3]

    return dp[N] % kMod
