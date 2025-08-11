class Solution:
  def countPathsWithXorValue(self, grid: list[list[int]], k: int) -> int:
    MOD = 1_000_000_007
    m = len(grid)
    n = len(grid[0])

    @functools.lru_cache(None)
    def count(i: int, j: int, xors: int) -> int:
      """
      Return the number of paths from (i, j) to (m - 1, n - 1) with XOR value
      `xors`.
      """
      if i == m or j == n:
        return 0
      xors ^= grid[i][j]
      if i == m - 1 and j == n - 1:
        return int(xors == k)
      right = count(i, j + 1, xors)
      down = count(i + 1, j, xors)
      return (right + down) % MOD

    return count(0, 0, 0)
