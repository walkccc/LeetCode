class Solution:
  def maxDistance(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    q = collections.deque()
    water = 0

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 0:
          water += 1
        else:
          q.append((i, j))

    if water == 0 or water == m * n:
      return -1

    ans = 0
    d = 0

    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        ans = d
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if grid[x][y] > 0:
            continue
          q.append((x, y))
          grid[x][y] = 2  # Mark as visited.
      d += 1

    return ans
