class Solution:
  def maxAmount(
      self,
      initialCurrency: str,
      pairs1: list[list[str]],
      rates1: list[float],
      pairs2: list[list[str]],
      rates2: list[float]
  ) -> float:
    # dp[currency] := the maximum amount of money to convert to `currency`
    dp: dict[str, float] = collections.defaultdict(float)
    dp[initialCurrency] = 1.0
    self._bellman(dp, pairs1, rates1)
    self._bellman(dp, pairs2, rates2)
    return dp[initialCurrency]

  def _bellman(
      self,
      dp: dict[str, float],
      pairs: list[list[str]],
      rates: list[float]
  ) -> None:
    for _ in range(len(pairs)):
      for (start, target), rate in zip(pairs, rates):
        dp[target] = max(dp[target], dp[start] * rate)
        dp[start] = max(dp[start], dp[target] / rate)
