class Solution:
  def getFood(self, grid: List[List[str]]) -> int:
    m = len(grid)
    n = len(grid[0])
    dirs = [0, 1, 0, -1, 0]
    ans = 0
    q = collections.deque([self._getStartLocation(grid)])

    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        for k in range(4):
          x = i + dirs[k]
          y = j + dirs[k + 1]
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

  def _getStartLocation(self, grid: List[List[str]]) -> Tuple[int, int]:
    for i, row in enumerate(grid):
      for j, cell in enumerate(row):
        if cell == '*':
          return (i, j)
