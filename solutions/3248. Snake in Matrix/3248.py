class Solution:
  def finalPositionOfSnake(self, n: int, commands: list[str]) -> int:
    directions = {
        "UP": (-1, 0),
        "RIGHT": (0, 1),
        "DOWN": (1, 0),
        "LEFT": (0, -1),
    }
    i = 0
    j = 0

    for command in commands:
      dx, dy = directions[command]
      i += dx
      j += dy

    return i * n + j
