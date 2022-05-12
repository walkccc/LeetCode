class Solution {
  public int movesToChessboard(int[][] board) {
    final int n = board.length;
    int rowSum = 0;
    int colSum = 0;
    int rowSwaps = 0;
    int colSwaps = 0;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) == 1)
          return -1;

    for (int i = 0; i < n; ++i) {
      rowSum += board[0][i];
      colSum += board[i][0];
    }

    if (rowSum != n / 2 && rowSum != (n + 1) / 2)
      return -1;
    if (colSum != n / 2 && colSum != (n + 1) / 2)
      return -1;

    for (int i = 0; i < n; ++i) {
      if (board[i][0] == (i & 1))
        ++rowSwaps;
      if (board[0][i] == (i & 1))
        ++colSwaps;
    }

    if (n % 2 == 1) {
      if (rowSwaps % 2 == 1)
        rowSwaps = n - rowSwaps;
      if (colSwaps % 2 == 1)
        colSwaps = n - colSwaps;
    } else {
      rowSwaps = Math.min(rowSwaps, n - rowSwaps);
      colSwaps = Math.min(colSwaps, n - colSwaps);
    }

    return (rowSwaps + colSwaps) / 2;
  }
}
