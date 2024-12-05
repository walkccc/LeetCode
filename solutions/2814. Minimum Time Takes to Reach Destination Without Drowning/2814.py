class Solution:
  def minimumSeconds(self, land: list[list[str]]) -> int:
    self.dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(land)
    n = len(land[0])
    floodDist = self._getFloodDist(land)
    startPos = self._getStartPos(land, 'S')

    q = collections.deque([startPos])
    seen = {startPos}

    step = 1
    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        for dx, dy in self.dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if land[x][y] == 'D':
            return step
          if floodDist[x][y] <= step or land[x][y] == 'X' or (x, y) in seen:
            continue
          q.append((x, y))
          seen.add((x, y))
      step += 1

    return -1

  def _getFloodDist(self, land: list[list[str]]) -> list[list[int]]:
    m = len(land)
    n = len(land[0])
    dist = [[math.inf] * n for _ in range(m)]
    q = collections.deque()
    seen = set()

    for i, row in enumerate(land):
      for j, cell in enumerate(row):
        if cell == '*':
          q.append((i, j))
          seen.add((i, j))

    d = 0
    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        dist[i][j] = d
        for dx, dy in self.dirs:
          x = i + dx
          y = j + dy
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if land[x][y] in 'XD' or (x, y) in seen:
            continue
          q.append((x, y))
          seen.add((x, y))
      d += 1

    return dist

  def _getStartPos(self, land: list[list[str]], c: str) -> tuple[int, int]:
    for i, row in enumerate(land):
      for j, cell in enumerate(row):
        if cell == c:
          return i, j
