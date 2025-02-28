class Solution:
  def maxDotProduct(self, A: list[int], B: list[int]) -> int:
    m = len(A)
    n = len(B)
    # dp[i][j] := the maximum dot product of the two subsequences nums[0..i)
    # and nums2[0..j)
    dp = [[-math.inf] * (n + 1) for _ in range(m + 1)]

    for i in range(m):
      for j in range(n):
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j],
                               max(0, dp[i][j]) + A[i] * B[j])

    return dp[m][n]
