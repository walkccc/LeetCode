class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    m = len(grid)
    n = len(grid[0])
    dirs = [0, 1, 0, -1, 0]

    def bfs(r, c):
      q = collections.deque([(r, c)])
      grid[r][c] = '2'  # Mark '2' as visited
      while q:
        i, j = q.popleft()
        for k in range(4):
          x = i + dirs[k]
          y = j + dirs[k + 1]
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if grid[x][y] != '1':
            continue
          q.append((x, y))
          grid[x][y] = '2'  # Mark '2' as visited

    ans = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == '1':
          bfs(i, j)
          ans += 1

    return ans
