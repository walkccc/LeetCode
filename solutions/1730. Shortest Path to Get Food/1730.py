class Solution:
  def getFood(self, grid: list[list[str]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    ans = 0
    q = collections.deque([self._getStartLocation(grid)])

    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if grid[x][y] == 'X':
            continue
          if grid[x][y] == '#':
            return ans + 1
          q.append((x, y))
          grid[x][y] = 'X'  # Mark as visited.
      ans += 1

    return -1

  def _getStartLocation(self, grid: list[list[str]]) -> tuple[int, int]:
    for i, row in enumerate(grid):
      for j, cell in enumerate(row):
        if cell == '*':
          return (i, j)
