class Solution:
  def probabilityOfHeads(self, prob: List[float], target: int) -> float:
    # dp[i][j] := the probability of tossing the first i coins with j heads
    dp = [[0] * (target + 1) for _ in range(len(prob) + 1)]
    dp[0][0] = 1.0

    for i in range(1, len(prob) + 1):
      for j in range(target + 1):
        dp[i][j] = (dp[i - 1][j - 1] * prob[i - 1] if j > 0 else 0) + \
            dp[i - 1][j] * (1 - prob[i - 1])

    return dp[len(prob)][target]
