class Solution {
  public int[] findPattern(int[][] board, String[] pattern) {
    for (int x = 0; x < board.length - pattern.length + 1; ++x)
      for (int y = 0; y < board[0].length - pattern[0].length() + 1; ++y)
        if (isMatch(board, x, y, pattern))
          return new int[] {x, y};
    return new int[] {-1, -1};
  }

  private boolean isMatch(int[][] board, int x, int y, String[] pattern) {
    Map<Integer, Character> digitToLetter = new HashMap<>();
    Map<Character, Integer> letterToDigit = new HashMap<>();
    for (int i = 0; i < pattern.length; ++i)
      for (int j = 0; j < pattern[i].length(); ++j) {
        final int digit = board[i + x][j + y];
        final char c = pattern[i].charAt(j);
        if (Character.isDigit(c)) {
          if (c - '0' != digit)
            return false;
        } else {
          if (digitToLetter.getOrDefault(digit, c) != c)
            return false;
          if (letterToDigit.getOrDefault(c, digit) != digit)
            return false;
          digitToLetter.putIfAbsent(digit, c);
          letterToDigit.putIfAbsent(c, digit);
        }
      }
    return true;
  }
}
