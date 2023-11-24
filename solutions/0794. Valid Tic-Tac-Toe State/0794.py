class Solution:
  def validTicTacToe(self, board: List[str]) -> bool:
    def isWin(c: str) -> bool:
      return any(row.count(c) == 3 for row in board) or \
          any(row.count(c) == 3 for row in list(zip(*board))) or \
          all(board[i][i] == c for i in range(3)) or \
          all(board[i][2 - i] == c for i in range(3))

    countX = sum(row.count('X') for row in board)
    countO = sum(row.count('O') for row in board)

    if countX < countO or countX - countO > 1:
      return False
    if isWin('X') and countX == countO or isWin('O') and countX != countO:
      return False

    return True
