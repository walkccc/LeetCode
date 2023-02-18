class Solution:
  def solveSudoku(self, board: List[List[str]]) -> None:
    def isValid(row: int, col: int, c: chr) -> bool:
      for i in range(9):
        if board[i][col] == c or \
           board[row][i] == c or \
           board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
          return False
      return True

    def solve(s: int) -> bool:
      if s == 81:
        return True

      i = s // 9
      j = s % 9

      if board[i][j] != '.':
        return solve(s + 1)

      for c in string.digits[1:]:
        if isValid(i, j, c):
          board[i][j] = c
          if solve(s + 1):
            return True
          board[i][j] = '.'

      return False

    solve(0)
