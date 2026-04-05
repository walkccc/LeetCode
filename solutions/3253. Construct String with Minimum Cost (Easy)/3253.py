class Solution:
  def minimumCost(self, target: str, words: list[str], costs: list[int]) -> int:
    n = len(target)
    # dp[i] := the minimum cost to construct target[0:i]
    dp = [0] + [math.inf] * n

    for i in range(1, n + 1):
      for j, (word, cost) in enumerate(zip(words, costs)):
        if (i >= len(word) and
            target[i - len(word):i] == word and
                dp[i - len(word)] != math.inf):
          dp[i] = min(dp[i], dp[i - len(word)] + cost)

    return dp[n] if dp[n] != math.inf else -1
