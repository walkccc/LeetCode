class Solution:
  def sumRemoteness(self, grid: List[List[int]]) -> int:
    n = len(grid)
    dirs = [0, 1, 0, -1, 0]
    summ = sum(max(0, cell) for row in grid for cell in row)
    ans = 0

    def dfs(i: int, j: int) -> Tuple[int, int]:
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

      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
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
