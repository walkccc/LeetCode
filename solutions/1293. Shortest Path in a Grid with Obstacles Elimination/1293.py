class Solution:
  def shortestPath(self, grid: list[list[int]], k: int) -> int:
    m = len(grid)
    n = len(grid[0])
    if m == 1 and n == 1:
      return 0

    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    q = collections.deque([(0, 0, k)])
    seen = {(0, 0, k)}

    step = 0
    while q:
      step += 1
      for _ in range(len(q)):
        i, j, eliminate = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if x == m - 1 and y == n - 1:
            return step
          if grid[x][y] == 1 and eliminate == 0:
            continue
          newEliminate = eliminate - grid[x][y]
          if (x, y, newEliminate) in seen:
            continue
          q.append((x, y, newEliminate))
          seen.add((x, y, newEliminate))

    return -1
