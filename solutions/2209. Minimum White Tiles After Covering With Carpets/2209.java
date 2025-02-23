class Solution {
  public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
    int[][] mem = new int[floor.length() + 1][numCarpets + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, kMax));
    return minimumWhiteTiles(floor, 0, numCarpets, carpetLen, mem);
  }

  private static final int kMax = 1000;

  // Returns the minimum number of visible white tiles of floor[i..n) after
  // covering at most j carpets.
  int minimumWhiteTiles(final String floor, int i, int j, int carpetLen, int[][] mem) {
    if (j < 0)
      return kMax;
    if (i >= floor.length())
      return 0;
    if (mem[i][j] != kMax)
      return mem[i][j];
    return mem[i][j] =
               Math.min(minimumWhiteTiles(floor, i + carpetLen, j - 1, carpetLen, mem),
                        minimumWhiteTiles(floor, i + 1, j, carpetLen, mem) + floor.charAt(i) - '0');
  }
}
