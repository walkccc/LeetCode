class Solution:
  def numTrees(self, n: int) -> int:
    # dp[i] := the number of unique BST's that store values 1..i
    dp = [1, 1] + [0] * (n - 1)

    for i in range(2, n + 1):
      for j in range(i):
        dp[i] += dp[j] * dp[i - j - 1]

    return dp[n]
