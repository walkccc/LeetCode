class Solution:
  def maximumProcessableQueries(
      self,
      nums: list[int],
      queries: list[int],
  ) -> int:
    n = len(nums)
    # dp[i][j] := the maximum number of queries processed if nums[i..j] are not
    # removed after processing dp[i][j] queries
    dp = [[0] * n for _ in range(n)]

    for d in range(n - 1, -1, -1):
      for i in range(n):
        j = i + d
        if j >= n:
          continue
        if i > 0:
          # Remove nums[i - 1] from nums[i - 1..j] if possible.
          dp[i][j] = max(dp[i][j], dp[i - 1][j] +
                         (nums[i - 1] >= queries[dp[i - 1][j]]))
        if j + 1 < n:
          # Remove nums[j + 1] from nums[i..j + 1] if possible.
          dp[i][j] = max(dp[i][j], dp[i][j + 1] +
                         (nums[j + 1] >= queries[dp[i][j + 1]]))
        if dp[i][j] == len(queries):
          return len(queries)

    return max(dp[i][i] + (nums[i] >= queries[dp[i][i]])
               for i in range(n))
