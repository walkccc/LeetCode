class Solution:
  def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
    dirs = [0, 1, 0, -1, 0]
    m = len(grid)
    n = len(grid[0])
    nFloors = 0
    cat = 0  # cat's position
    mouse = 0  # mouse's position

    def hash(i: int, j: int) -> int:
      return i * n + j

    for i in range(m):
      for j in range(n):
        if grid[i][j] != '#':
          nFloors += 1
        if grid[i][j] == 'C':
          cat = hash(i, j)
        elif grid[i][j] == 'M':
          mouse = hash(i, j)

    @functools.lru_cache(None)
    def dp(cat: int, mouse: int, turn: int) -> bool:
      """
      Returns True if the mouse can win, where the cat is on (i / 8, i % 8),
      the mouse is on (j / 8, j % 8), and the turns = k.
      """
      # We already search the whole touchable grid.
      if turn == nFloors * 2:
        return False

      if turn % 2 == 0:
        # the mouse's turn
        i = mouse // n
        j = mouse % n
        for k in range(4):
          for jump in range(mouseJump + 1):
            x = i + dirs[k] * jump
            y = j + dirs[k + 1] * jump
            if x < 0 or x == m or y < 0 or y == n:
              break
            if grid[x][y] == '#':
              break
            # The mouse eats the food, so the mouse wins.
            if grid[x][y] == 'F':
              return True
            if dp(cat, hash(x, y), turn + 1):
              return True
        # The mouse can't win, so the mouse loses.
        return False
      else:
        # the cat's turn
        i = cat // n
        j = cat % n
        for k in range(4):
          for jump in range(catJump + 1):
            x = i + dirs[k] * jump
            y = j + dirs[k + 1] * jump
            if x < 0 or x == m or y < 0 or y == n:
              break
            if grid[x][y] == '#':
              break
            # The cat eats the food, so the mouse loses.
            if grid[x][y] == 'F':
              return False
            nextCat = hash(x, y)
            # The cat catches the mouse, so the mouse loses.
            if nextCat == mouse:
              return False
            if not dp(nextCat, mouse, turn + 1):
              return False
        # The cat can't win, so the mouse wins.
        return True

    return dp(cat, mouse, 0)
