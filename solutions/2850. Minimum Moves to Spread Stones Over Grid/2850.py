class Solution:
  def minimumMoves(self, grid: List[List[int]]) -> int:
    if sum(row.count(0) for row in grid) == 0:
      return 0

    ans = math.inf

    for i in range(3):
      for j in range(3):
        if grid[i][j] == 0:
          for x in range(3):
            for y in range(3):
              if grid[x][y] > 1:
                grid[x][y] -= 1
                grid[i][j] += 1
                ans = min(ans, abs(x - i) + abs(y - j) + self.minimumMoves(grid))
                grid[x][y] += 1
                grid[i][j] -= 1

    return ans
