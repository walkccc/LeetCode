class Solution:
  def sumRemoteness(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    n = len(grid)
    summ = sum(max(0, cell) for row in grid for cell in row)
    ans = 0

    def dfs(i: int, j: int) -> tuple[int, int]:
      """
      Returns the (count, componentSum) of the connected component that contains
      (x, y).
      """
      if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
        return (0, 0)
      if grid[i][j] == -1:
        return (0, 0)

      count = 1
      componentSum = grid[i][j]
      grid[i][j] = -1  # Mark as visited.

      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        nextCount, nextComponentSum = dfs(x, y)
        count += nextCount
        componentSum += nextComponentSum

      return (count, componentSum)

    for i in range(n):
      for j in range(n):
        if grid[i][j] > 0:
          count, componentSum = dfs(i, j)
          ans += (summ - componentSum) * count

    return ans
