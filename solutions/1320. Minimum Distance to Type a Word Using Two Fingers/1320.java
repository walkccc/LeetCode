class Solution {
  public int minimumDistance(String word) {
    Integer[][][] mem = new Integer[27][27][word.length()];
    return minimumDistance(word, 26, 26, 0, mem);
  }

  // Returns the minimum distance to type `word`, where the left finger is on
  // the i-th letter, the right finger is on the j-th letter, and word[0..k)
  // have been written.
  private int minimumDistance(final String word, int i, int j, int k, Integer[][][] mem) {
    if (k == word.length())
      return 0;
    if (mem[i][j][k] != null)
      return mem[i][j][k];
    final int c = word.charAt(k) - 'A';
    final int moveLeft = dist(i, c) + minimumDistance(word, c, j, k + 1, mem);
    final int moveRight = dist(j, c) + minimumDistance(word, i, c, k + 1, mem);
    return mem[i][j][k] = Math.min(moveLeft, moveRight);
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
