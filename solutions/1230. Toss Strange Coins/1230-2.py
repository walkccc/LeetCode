class Solution:
  def probabilityOfHeads(self, prob: List[float], target: int) -> float:
    # dp[j] := the probability of tossing the coins so far with j heads
    dp = [1.0] + [0] * len(prob)

    for p in prob:
      for j in range(target, -1, -1):
        dp[j] = (dp[j - 1] * p if j > 0 else 0) + dp[j] * (1 - p)

    return dp[target]
