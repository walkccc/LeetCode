class Solution:
  def minCost(self, nums: list[int], k: int) -> int:
    kMax = 1001
    n = len(nums)
    # trimmedLength[i][j] := trimmed(nums[i..j]).length
    trimmedLength = [[0] * n for _ in range(n)]
    # dp[i] := the minimum cost to split nums[i..n)
    dp = [math.inf] * n + [0]

    for i in range(n):
      length = 0
      count = [0] * kMax
      for j in range(i, n):
        count[nums[j]] += 1
        if count[nums[j]] == 2:
          length += 2
        elif count[nums[j]] > 2:
          length += 1
        trimmedLength[i][j] = length

    dp[n] = 0

    for i in range(n - 1, -1, -1):
      for j in range(i, n):
        dp[i] = min(dp[i], k + trimmedLength[i][j] + dp[j + 1])

    return dp[0]
