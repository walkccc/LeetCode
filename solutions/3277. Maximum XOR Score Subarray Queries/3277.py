class Solution:
  def maximumSubarrayXor(
      self,
      nums: list[int],
      queries: list[list[int]]
  ) -> list[int]:
    n = len(nums)
    # xors[i][j] := the XOR score of nums[i..j]
    xors = [[0] * n for _ in range(n)]
    # dp[i][j] := the maximum XOR score of nums[i..j]
    dp = [[0] * n for _ in range(n)]

    for i, num in enumerate(nums):
      xors[i][i] = num
      dp[i][i] = num

    for d in range(1, n):
      for i in range(n - d):
        j = i + d
        xors[i][j] = xors[i][j - 1] ^ xors[i + 1][j]
        dp[i][j] = max(xors[i][j], dp[i][j - 1], dp[i + 1][j])

    return [dp[l][r] for l, r in queries]
