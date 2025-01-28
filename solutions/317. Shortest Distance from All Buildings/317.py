class Solution:
  def shortestDistance(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    nBuildings = sum(a == 1 for row in grid for a in row)
    ans = math.inf
    # dist[i][j] := the total distance of grid[i][j] (0) to reach all the
    # buildings (1)
    dist = [[0] * n for _ in range(m)]
    # reachCount[i][j] := the number of buildings (1) grid[i][j] (0) can reach
    reachCount = [[0] * n for _ in range(m)]

    def bfs(row: int, col: int) -> bool:
      q = collections.deque([(row, col)])
      seen = {(row, col)}
      seenBuildings = 1

      step = 1
      while q:
        for _ in range(len(q)):
          i, j = q.popleft()
          for dx, dy in dirs:
            x = i + dx
            y = j + dy
            if x < 0 or x == m or y < 0 or y == n:
              continue
            if (x, y) in seen:
              continue
            seen.add((x, y))
            if not grid[x][y]:
              dist[x][y] += step
              reachCount[x][y] += 1
              q.append((x, y))
            elif grid[x][y] == 1:
              seenBuildings += 1
        step += 1

      # True if all the buildings (1) are connected
      return seenBuildings == nBuildings

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 1:  # BFS from this building.
          if not bfs(i, j):
            return -1

    for i in range(m):
      for j in range(n):
        if reachCount[i][j] == nBuildings:
          ans = min(ans, dist[i][j])

    return -1 if ans == math.inf else ans
