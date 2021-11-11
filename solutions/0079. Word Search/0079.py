class Solution:
  def exist(self, board: List[List[str]], word: str) -> bool:
    def dfs(i: int, j: int, s: int) -> bool:
      if i < 0 or i == len(board) or j < 0 or j == len(board[0]):
        return False
      if board[i][j] != word[s] or board[i][j] == '*':
        return False
      if s == len(word) - 1:
        return True

      cache = board[i][j]
      board[i][j] = '*'
      isExist = \
          dfs(i + 1, j, s + 1) or \
          dfs(i - 1, j, s + 1) or \
          dfs(i, j + 1, s + 1) or \
          dfs(i, j - 1, s + 1)
      board[i][j] = cache

      return isExist

    return any(dfs(i, j, 0) for i in range(len(board)) for j in range(len(board[0])))
