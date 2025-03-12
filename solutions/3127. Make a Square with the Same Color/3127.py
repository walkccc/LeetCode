class Solution:
  def canMakeSquare(self, grid: list[list[str]]) -> bool:
    for i in range(2):
      for j in range(2):
        black = 0
        white = 0
        for x in range(2):
          for y in range(2):
            if grid[i + x][j + y] == 'B':
              black += 1
            else:
              white += 1
        if black >= 3 or white >= 3:
          return True
    return False
