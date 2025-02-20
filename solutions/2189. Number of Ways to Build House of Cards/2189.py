class Solution:
  def houseOfCards(self, n: int) -> int:
    # dp[i] := the number of valid result for i cards
    dp = [1] + [0] * n

    for baseCards in range(2, n + 1, 3):
      for i in range(n, baseCards - 1, -1):
        # Use `baseCards` as the base, so we're left with `i - baseCards` cards.
        dp[i] += dp[i - baseCards]

    return dp[n]
