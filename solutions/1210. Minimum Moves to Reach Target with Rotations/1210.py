from enum import IntEnum


class Pos(IntEnum):
  kHorizontal = 0
  kVertical = 1


class Solution:
  def minimumMoves(self, grid: List[List[int]]) -> int:
    n = len(grid)
    ans = 0
    # the state of (x, y, pos)
    # pos := 0 (horizontal) / 1 (vertical)
    q = collections.deque([(0, 0, Pos.kHorizontal)])
    seen = {(0, 0, Pos.kHorizontal)}

    def canMoveRight(x: int, y: int, pos: Pos) -> bool:
      if pos == Pos.kHorizontal:
        return y + 2 < n and not grid[x][y + 2]
      return y + 1 < n and not grid[x][y + 1] and not grid[x + 1][y + 1]

    def canMoveDown(x: int, y: int, pos: Pos) -> bool:
      if pos == Pos.kVertical:
        return x + 2 < n and not grid[x + 2][y]
      return x + 1 < n and not grid[x + 1][y] and not grid[x + 1][y + 1]

    def canRotateClockwise(x: int, y: int, pos: Pos) -> bool:
      return pos == Pos.kHorizontal and x + 1 < n and \
          not grid[x + 1][y + 1] and not grid[x + 1][y]

    def canRotateCounterclockwise(x: int, y: int, pos: Pos) -> bool:
      return pos == Pos.kVertical and y + 1 < n and \
          not grid[x + 1][y + 1] and not grid[x][y + 1]

    while q:
      for _ in range(len(q)):
        x, y, pos = q.popleft()
        if x == n - 1 and y == n - 2 and pos == Pos.kHorizontal:
          return ans
        if canMoveRight(x, y, pos) and (x, y + 1, pos) not in seen:
          q.append((x, y + 1, pos))
          seen.add((x, y + 1, pos))
        if canMoveDown(x, y, pos) and (x + 1, y, pos) not in seen:
          q.append((x + 1, y, pos))
          seen.add((x + 1, y, pos))
        newPos = Pos.kVertical if pos == Pos.kHorizontal else Pos.kHorizontal
        if (canRotateClockwise(x, y, pos) or canRotateCounterclockwise(x, y, pos)) and \
                (x, y, newPos) not in seen:
          q.append((x, y, newPos))
          seen.add((x, y, newPos))
      ans += 1

    return -1
