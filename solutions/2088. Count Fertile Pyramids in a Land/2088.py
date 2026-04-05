class Solution:
  def countPyramids(self, grid: list[list[int]]) -> int:
    # dp[i][j] := the maximum height of the pyramid for which it is the apex
    def count(dp: list[list[int]]) -> int:
      ans = 0
      for i in range(len(dp) - 2, -1, -1):
        for j in range(1, len(dp[0]) - 1):
          if dp[i][j] == 1:
            dp[i][j] = min(dp[i + 1][j - 1],
                           dp[i + 1][j],
                           dp[i + 1][j + 1]) + 1
            ans += dp[i][j] - 1
      return ans

    return count(deepcopy(grid)[::-1]) + count(grid)
