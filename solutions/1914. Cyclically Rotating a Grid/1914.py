class Solution:
  def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    t = 0  # top
    l = 0  # left
    b = m - 1  # bottom
    r = n - 1  # right

    while t < b and l < r:
      elementInThisLayer = 2 * (b - t + 1) + 2 * (r - l + 1) - 4
      netRotations = k % elementInThisLayer
      for _ in range(netRotations):
        topLeft = grid[t][l]
        for j in range(l, r):
          grid[t][j] = grid[t][j + 1]
        for i in range(t, b):
          grid[i][r] = grid[i + 1][r]
        for j in range(r, l, - 1):
          grid[b][j] = grid[b][j - 1]
        for i in range(b, t, -1):
          grid[i][l] = grid[i - 1][l]
        grid[t + 1][l] = topLeft
      t += 1
      l += 1
      b -= 1
      r -= 1

    return grid
