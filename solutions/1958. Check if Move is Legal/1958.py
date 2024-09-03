class Solution:
  def checkMove(
      self,
      board: list[list[str]],
      rMove: int,
      cMove: int,
      color: str,
  ) -> bool:
    dirs = ((-1, -1), (-1, 0), (-1, 1), (0, -1),
            (0, 1), (1, -1), (1, 0), (1, 1))

    for dx, dy in dirs:
      cellsCount = 2
      i = rMove + dx
      j = cMove + dy
      while 0 <= i < 8 and 0 <= j < 8:
        # There are no free cells in between.
        if board[i][j] == '.':
          break
        # Need >= 3 cells.
        if cellsCount == 2 and board[i][j] == color:
          break
        # >= 3 cells.
        if board[i][j] == color:
          return True
        i += dx
        j += dy
        cellsCount += 1

    return False
