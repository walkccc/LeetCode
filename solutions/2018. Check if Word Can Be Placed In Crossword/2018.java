class Solution {
  public boolean placeWordInCrossword(char[][] board, String word) {
    for (char[][] state : new char[][][] {board, getRotated(board)})
      for (char[] chars : state)
        for (final String token : String.valueOf(chars).split("#"))
          for (final String letters :
               new String[] {word, new StringBuilder(word).reverse().toString()})
            if (letters.length() == token.length())
              if (canFit(letters, token))
                return true;
    return false;
  }

  private char[][] getRotated(char[][] board) {
    final int m = board.length;
    final int n = board[0].length;
    char[][] rotated = new char[n][m];
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        rotated[j][i] = board[i][j];
    return rotated;
  }

  private boolean canFit(final String letters, final String token) {
    for (int i = 0; i < letters.length(); ++i)
      if (token.charAt(i) != ' ' && token.charAt(i) != letters.charAt(i))
        return false;
    return true;
  }
}
