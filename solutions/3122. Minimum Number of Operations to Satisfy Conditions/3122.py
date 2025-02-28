class Solution:
  def minimumOperations(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    count = [[0] * 10 for _ in range(n)]

    for row in grid:
      for j, num in enumerate(row):
        count[j][num] += 1

    @functools.lru_cache(None)
    def dp(i: int, prev: int) -> int:
      """
      Returns the number of minimum operations needed to make grid[:][j..n)
      satisfy the conditions, where the (j - 1)-th column is filled with `prev`.
      """
      if i == n:
        return 0

      res = math.inf

      for num in range(10):
        if i == 0 or num != prev:
          res = min(res, m - count[i][num] + dp(i + 1, num))

      return res

    return dp(0, 0)
