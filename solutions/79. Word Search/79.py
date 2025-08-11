class Solution:
  def exist(self, board: list[list[str]], word: str) -> bool:
    m = len(board)
    n = len(board[0])

    def dfs(i: int, j: int, s: int) -> bool:
      if i < 0 or i == m or j < 0 or j == n:
        return False
      if board[i][j] != word[s] or board[i][j] == '*':
        return False
      if s == len(word) - 1:
        return True

      cache = board[i][j]
      board[i][j] = '*'
      isExist = (dfs(i + 1, j, s + 1) or
                 dfs(i - 1, j, s + 1) or
                 dfs(i, j + 1, s + 1) or
                 dfs(i, j - 1, s + 1))
      board[i][j] = cache

      return isExist

    return any(dfs(i, j, 0)
               for i in range(m)
               for j in range(n))
