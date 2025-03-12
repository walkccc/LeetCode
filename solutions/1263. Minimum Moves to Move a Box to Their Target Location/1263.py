class Solution:
  def minPushBox(self, grid: list[list[str]]) -> int:
    DIRS = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(grid)
    n = len(grid[0])

    for i in range(m):
      for j in range(n):
        if grid[i][j] == 'B':
          box = (i, j)
        elif grid[i][j] == 'S':
          player = (i, j)
        elif grid[i][j] == 'T':
          target = (i, j)

    def isInvalid(playerX: int, playerY: int) -> bool:
      return (playerX < 0 or playerX == m or playerY < 0 or playerY == n or
              grid[playerX][playerY] == '#')

    def canGoTo(
        playerX: int,
        playerY: int,
        fromX: int,
        fromY: int,
        boxX: int,
        boxY: int
    ) -> bool:
      """Returns True if (playerX, playerY) can go to (fromX, fromY)."""
      q = collections.deque([(playerX, playerY)])
      seen = {(playerX, playerY)}

      while q:
        i, j = q.popleft()
        if i == fromX and j == fromY:
          return True
        for dx, dy in DIRS:
          x = i + dx
          y = j + dy
          if isInvalid(x, y):
            continue
          if (x, y) in seen:
            continue
          if x == boxX and y == boxY:
            continue
          q.append((x, y))
          seen.add((x, y))

      return False

    # (boxX, boxY, playerX, playerY)
    q = collections.deque([(box[0], box[1], player[0], player[1])])
    seen = {(box[0], box[1], player[0], player[1])}

    step = 0
    while q:
      for _ in range(len(q)):
        boxX, boxY, playerX, playerY = q.popleft()
        if boxX == target[0] and boxY == target[1]:
          return step
        for k, (dx, dy) in enumerate(DIRS):
          nextBoxX = boxX + dx
          nextBoxY = boxY + dy
          if isInvalid(nextBoxX, nextBoxY):
            continue
          if (nextBoxX, nextBoxY, boxX, boxY) in seen:
            continue
          fromX = boxX + DIRS[(k + 2) % 4][0]
          fromY = boxY + DIRS[(k + 2) % 4][1]
          if isInvalid(fromX, fromY):
            continue
          if canGoTo(playerX, playerY, fromX, fromY, boxX, boxY):
            q.append((nextBoxX, nextBoxY, boxX, boxY))
            seen.add((nextBoxX, nextBoxY, boxX, boxY))
      step += 1

    return -1
