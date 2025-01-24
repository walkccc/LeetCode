class Solution:
  def maximumMinutes(self, grid: list[list[int]]) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    kMax = len(grid) * len(grid[0])
    fireGrid = [[-1] * len(grid[0]) for _ in range(len(grid[0]))]
    self._buildFireGrid(grid, fireGrid, dirs)

    ans = -1
    l = 0
    r = kMax

    while l <= r:
      m = (l + r) // 2
      if self._canStayFor(grid, fireGrid, m, dirs):
        ans = m
        l = m + 1
      else:
        r = m - 1

    return 1e9 if ans == kMax else ans

  def _buildFireGrid(
      self,
      grid: list[list[int]],
      fireMinute: list[list[int]],
      dirs: list[int],
  ) -> None:
    minuteFromFire = 0
    q = collections.deque()

    for i in range(len(grid)):
      for j in range(len(grid[0])):
        if grid[i][j] == 1:  # the fire
          q.append((i, j))
          fireMinute[i][j] = 0

    while q:
      minuteFromFire += 1
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == len(grid) or y < 0 or y == len(grid[0]):
            continue
          if grid[x][y] == 2:  # the wall
            continue
          if fireMinute[x][y] != -1:
            continue
          fireMinute[x][y] = minuteFromFire
          q.append((x, y))

  def _canStayFor(
      self,
      grid: list[list[int]],
      fireMinute: list[list[int]],
      minute: int, dirs: list[int],
  ) -> bool:
    q = collections.deque([(0, 0)])  # the start position
    seen = {(0, 0)}

    while q:
      minute += 1
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == len(grid) or y < 0 or y == len(grid[0]):
            continue
          if grid[x][y] == 2:  # the wall
            continue
          if x == len(grid) - 1 and y == len(grid[0]) - 1:
            if fireMinute[x][y] != -1 and fireMinute[x][y] < minute:
              continue
            return True
          if fireMinute[x][y] != -1 and fireMinute[x][y] <= minute:
            continue
          if seen[x][y]:
            continue
          q.append((x, y))
          seen.add((x, y))

    return False
