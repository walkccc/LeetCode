class Solution:
  def movesToChessboard(self, board: List[List[int]]) -> int:
    n = len(board)

    if any(board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j] for i in range(n) for j in range(n)):
      return -1

    rowSum = sum(board[0])
    colSum = sum(board[i][0] for i in range(n))

    if rowSum != n // 2 and rowSum != (n + 1) // 2:
      return -1
    if colSum != n // 2 and colSum != (n + 1) // 2:
      return -1

    rowSwaps = sum(board[i][0] == (i & 1) for i in range(n))
    colSwaps = sum(board[0][i] == (i & 1) for i in range(n))

    if n & 1:
      if rowSwaps & 1:
        rowSwaps = n - rowSwaps
      if colSwaps & 1:
        colSwaps = n - colSwaps
    else:
      rowSwaps = min(rowSwaps, n - rowSwaps)
      colSwaps = min(colSwaps, n - colSwaps)

    return (rowSwaps + colSwaps) // 2
