from enum import IntEnum


class Pos(IntEnum):
  HORIZONTAL = 0
  VERTICAL = 1


class Solution:
  def minimumMoves(self, grid: List[List[int]]) -> int:
    n = len(grid)
    ans = 0
    # state of (x, y, pos)
    # pos := 0 (horizontal) // 1 (vertical)
    q = deque([(0, 0, Pos.HORIZONTAL)])
    seen = {(0, 0, Pos.HORIZONTAL)}

    def canMoveRight(x: int, y: int, pos: Pos) -> bool:
      if pos == Pos.HORIZONTAL:
        return y + 2 < n and not grid[x][y + 2]
      return y + 1 < n and not grid[x][y + 1] and not grid[x + 1][y + 1]

    def canMoveDown(x: int, y: int, pos: Pos) -> bool:
      if pos == Pos.VERTICAL:
        return x + 2 < n and not grid[x + 2][y]
      return x + 1 < n and not grid[x + 1][y] and not grid[x + 1][y + 1]

    def canRotateClockwise(x: int, y: int, pos: Pos) -> bool:
      return pos == Pos.HORIZONTAL and x + 1 < n and \
          not grid[x + 1][y + 1] and not grid[x + 1][y]

    def canRotateCounterclockwise(x: int, y: int, pos: Pos) -> bool:
      return pos == Pos.VERTICAL and y + 1 < n and \
          not grid[x + 1][y + 1] and not grid[x][y + 1]

    while q:
      for _ in range(len(q)):
        x, y, pos = q.popleft()
        if x == n - 1 and y == n - 2 and pos == Pos.HORIZONTAL:
          return ans
        if canMoveRight(x, y, pos) and (x, y + 1, pos) not in seen:
          q.append((x, y + 1, pos))
          seen.add((x, y + 1, pos))
        if canMoveDown(x, y, pos) and (x + 1, y, pos) not in seen:
          q.append((x + 1, y, pos))
          seen.add((x + 1, y, pos))
        newPos = Pos.VERTICAL if pos == Pos.HORIZONTAL else Pos.HORIZONTAL
        if (canRotateClockwise(x, y, pos) or canRotateCounterclockwise(x, y, pos)) and \
                (x, y, newPos) not in seen:
          q.append((x, y, newPos))
          seen.add((x, y, newPos))
      ans += 1

    return -1
