class Solution:
  def findSafeWalk(self, grid: list[list[int]], health: int) -> bool:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])
    initialHealth = health - grid[0][0]
    q = collections.deque([(0, 0, initialHealth)])
    seen = {(0, 0, initialHealth)}

    while q:
      for _ in range(len(q)):
        i, j, h = q.popleft()
        if i == m - 1 and j == n - 1 and h > 0:
          return True
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          nextHealth = h - grid[x][y]
          if nextHealth <= 0 or (x, y, nextHealth) in seen:
            continue
          q.append((x, y, nextHealth))
          seen.add((x, y, nextHealth))

    return False
