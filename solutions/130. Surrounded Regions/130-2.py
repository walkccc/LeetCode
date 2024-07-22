class Solution:
  def solve(self, board: List[List[str]]) -> None:
    if not board:
      return

    m = len(board)
    n = len(board[0])

    def dfs(i: int, j: int) -> None:
      """Marks the grids with 'O' that stretch from the four sides to '*'."""
      if i < 0 or i == m or j < 0 or j == n:
        return
      if board[i][j] != 'O':
        return
      board[i][j] = '*'
      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    for i in range(m):
      for j in range(n):
        if i * j == 0 or i == m - 1 or j == n - 1:
          dfs(i, j)

    for row in board:
      for i, c in enumerate(row):
        row[i] = 'O' if c == '*' else 'X'
