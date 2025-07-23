class Solution:
  def lenOfVDiagonal(self, grid: list[list[int]]) -> int:
    DIRS = ((-1, 1), (1, 1), (1, -1), (-1, -1))

    @functools.lru_cache(None)
    def dfs(i: int, j: int, turned: bool, num: int, dir: int) -> int:
      if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
        return 0
      if grid[i][j] != num:
        return 0

      nextNum = 0 if num == 2 else 2
      dx, dy = DIRS[dir]
      res = 1 + dfs(i + dx, j + dy, turned, nextNum, dir)

      if not turned:
        nextDir = (dir + 1) % 4
        nextDx, nextDy = DIRS[nextDir]
        res = max(res, 1 + dfs(i + nextDx, j + nextDy, 1, nextNum, nextDir))

      return res

    return max((1 + dfs(i + dx, j + dy, 0, 2, d)
                for i, row in enumerate(grid)
                for j, num in enumerate(row)
                if num == 1
                for d, (dx, dy) in enumerate(DIRS)),
               default=0)
