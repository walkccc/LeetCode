class TicTacToe {
 public:
  TicTacToe(int n) : n(n), rows(n), cols(n) {}

  /**
   * Player {player} makes a move at ({row}, {col}).
   *
   * @param row    The row of the board.
   * @param col    The column of the board.
   * @param player The player, can be either 1 or 2.
   * @return The current winning condition, can be either:
   *         0: No one wins.
   *         1: Player 1 wins.
   *         2: Player 2 wins.
   */
  int move(int row, int col, int player) {
    const int toAdd = player == 1 ? 1 : -1;
    const int target = player == 1 ? n : -n;

    if (row == col) {
      diag += toAdd;
      if (diag == target)
        return player;
    }

    if (row + col == n - 1) {
      antiDiag += toAdd;
      if (antiDiag == target)
        return player;
    }

    rows[row] += toAdd;
    if (rows[row] == target)
      return player;

    cols[col] += toAdd;
    if (cols[col] == target)
      return player;

    return 0;
  }

 private:
  const int n;
  // Record count('X') - count('O').
  vector<int> rows;
  vector<int> cols;
  int diag = 0;
  int antiDiag = 0;
};
