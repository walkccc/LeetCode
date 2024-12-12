class Solution:
  def countSubmatrices(self, grid: list[list[int]], k: int) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    # prefix[i][j] := the sum of matrix[0..i)[0..j)
    prefix = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m):
      for j in range(n):
        prefix[i + 1][j + 1] = (grid[i][j] + prefix[i][j + 1] +
                                prefix[i + 1][j] - prefix[i][j])
        if prefix[i + 1][j + 1] <= k:
          ans += 1

    return ans
