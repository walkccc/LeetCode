class Solution:
  def solve(self, board: list[list[str]]) -> None:
    if not board:
      return

    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(board)
    n = len(board[0])
    q = collections.deque()

    for i in range(m):
      for j in range(n):
        if i * j == 0 or i == m - 1 or j == n - 1:
          if board[i][j] == 'O':
            q.append((i, j))
            board[i][j] = '*'

    # Mark the grids that stretch from the four sides with '*'.
    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        x = i + dx
        y = j + dy
        if x < 0 or x == m or y < 0 or y == n:
          continue
        if board[x][y] != 'O':
          continue
        q.append((x, y))
        board[x][y] = '*'

    for row in board:
      for i, c in enumerate(row):
        row[i] = 'O' if c == '*' else 'X'
