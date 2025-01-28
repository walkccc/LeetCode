class Solution:
  def maxScore(self, a: list[int], b: list[int]) -> int:
    # dp[i] := the maximum score of a[0..i]
    dp = [-math.inf] * 4

    for num in b:
      for i in reversed(range(4)):
        # Skip `num` or pair a[i] with `num`.
        dp[i] = max(dp[i], (dp[i - 1] if i > 0 else 0) + a[i] * num)

    return dp[3]
