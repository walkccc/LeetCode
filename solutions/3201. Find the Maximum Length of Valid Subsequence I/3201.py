class Solution:
  def maximumLength(self, nums: list[int]) -> int:
    # dp[i][j] := the maximum length of a valid subsequence, where the last
    # number mod k equal to i and the next desired number mod k equal to j
    dp = [[0] * 2 for _ in range(2)]

    # Extend the pattern xyxyxy...xy.
    for x in nums:
      for y in range(2):
        dp[x % 2][y] = dp[y][x % 2] + 1

    return max(map(max, dp))
