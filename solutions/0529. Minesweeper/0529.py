class Solution:
  def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
    if board[click[0]][click[1]] == 'M':
      board[click[0]][click[1]] = 'X'
      return board

    dirs = [(-1, -1), (-1, 0), (-1, 1), (0, -1),
            (0, 1), (1, -1), (1, 0), (1, 1)]

    def getMinesCount(i: int, j: int) -> int:
      minesCount = 0
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == len(board) or y < 0 or y == len(board[0]):
          continue
        if board[x][y] == 'M':
          minesCount += 1
      return minesCount

    def dfs(i: int, j: int) -> None:
      if i < 0 or i == len(board) or j < 0 or j == len(board[0]):
        return
      if board[i][j] != 'E':
        return

      minesCount = getMinesCount(i, j)
      board[i][j] = 'B' if minesCount == 0 else str(minesCount)

      if minesCount == 0:
        for dx, dy in dirs:
          dfs(i + dx, j + dy)

    dfs(click[0], click[1])

    return board
