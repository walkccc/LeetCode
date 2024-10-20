class Solution {
  public boolean validTicTacToe(String[] board) {
    final int countX = sum(board, 'X');
    final int countO = sum(board, 'O');

    if (countX < countO || countX - countO > 1)
      return false;
    if (isWinned(board, 'X') && countX == countO || //
        isWinned(board, 'O') && countX != countO)
      return false;

    return true;
  }

  private int sum(final String[] board, char c) {
    int ans = 0;

    for (final String row : board)
      ans += row.chars().filter(i -> i == c).count();

    return ans;
  }

  private boolean isWinned(final String[] board, char c) {
    String[] rotated = rotate(board);

    return Arrays.stream(board).anyMatch(row -> row.chars().filter(i -> i == c).count() == 3) ||
        Arrays.stream(rotated).anyMatch(row -> row.chars().filter(i -> i == c).count() == 3) ||
        board[0].charAt(0) == c && board[1].charAt(1) == c && board[2].charAt(2) == c ||
        board[0].charAt(2) == c && board[1].charAt(1) == c && board[2].charAt(0) == c;
  }

  private String[] rotate(final String[] board) {
    String[] rotated = new String[3];

    for (final String row : board)
      for (int i = 0; i < 3; ++i)
        rotated[i] += row.charAt(i);

    return rotated;
  }
}
