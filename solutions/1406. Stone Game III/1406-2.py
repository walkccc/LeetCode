class Solution:
  def stoneGameIII(self, stoneValue: List[int]) -> str:
    n = len(stoneValue)

    # dp[i] := max "relative score" Alice can make w/ stoneValue[i:]
    dp = [-inf] * n + [0]

    for i in range(n - 1, -1, -1):
      sum = 0
      for j in range(i, i + 3):
        if j == n:
          break
        sum += stoneValue[j]
        dp[i] = max(dp[i], sum - dp[j + 1])

    score = dp[0]
    if score == 0:
      return 'Tie'
    return 'Alice' if score > 0 else 'Bob'
