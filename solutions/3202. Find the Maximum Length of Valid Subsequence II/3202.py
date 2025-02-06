class Solution:
  # Similar to 3201. Find the Maximum Length of Valid Subsequence I
  def maximumLength(self, nums: list[int], k: int) -> int:
    # dp[i][j] := the maximum length of a valid subsequence, where the last
    # number mod k equal to i and the next desired number mod k equal to j
    dp = [[0] * k for _ in range(k)]

    # Extend the pattern xyxyxy...xy.
    for x in nums:
      for y in range(k):
        dp[x % k][y] = dp[y][x % k] + 1

    return max(map(max, dp))
