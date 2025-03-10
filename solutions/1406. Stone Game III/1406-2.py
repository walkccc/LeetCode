class Solution:
  def stoneGameIII(self, stoneValue: list[int]) -> str:
    n = len(stoneValue)
    # dp[i] := the maximum relative score Alice can make with stoneValue[i..n)
    dp = [-math.inf] * n + [0]

    for i in reversed(range(n)):
      summ = 0
      for j in range(i, i + 3):
        if j == n:
          break
        summ += stoneValue[j]
        dp[i] = max(dp[i], summ - dp[j + 1])

    score = dp[0]
    if score == 0:
      return 'Tie'
    return 'Alice' if score > 0 else 'Bob'
