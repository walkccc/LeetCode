class Solution {
  public int minimumDistance(String word) {
    // dp[i][j][k] := the minimum distance to type the `word`, where the left
    // finger is on the i-th letter, the right finger is on the j-th letter, and
    // the words[0..k) have been written
    dp = new Integer[27][27][word.length()];
    return minimumDistance(word, 26, 26, 0);
  }

  private Integer[][][] dp;

  private int minimumDistance(final String word, int i, int j, int k) {
    if (k == word.length())
      return 0;
    if (dp[i][j][k] != null)
      return dp[i][j][k];
    final int next = word.charAt(k) - 'A';
    final int moveLeft = dist(i, next) + minimumDistance(word, next, j, k + 1);
    final int moveRight = dist(j, next) + minimumDistance(word, i, next, k + 1);
    return dp[i][j][k] = Math.min(moveLeft, moveRight);
  }

  private int dist(int a, int b) {
    if (a == 26) // the first hovering state
      return 0;
    final int x1 = a / 6;
    final int y1 = a % 6;
    final int x2 = b / 6;
    final int y2 = b % 6;
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
  }
}
