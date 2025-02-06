class Solution:
  def numIslands(self, grid: list[list[str]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])

    def bfs(r, c):
      q = collections.deque([(r, c)])
      grid[r][c] = '2'  # Mark '2' as visited.
      while q:
        i, j = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if grid[x][y] != '1':
            continue
          q.append((x, y))
          grid[x][y] = '2'  # Mark '2' as visited.

    ans = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == '1':
          bfs(i, j)
          ans += 1

    return ans
