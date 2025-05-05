class Solution {
  public int strangePrinter(String s) {
    final int n = s.length();
    int[][] mem = new int[n][n];
    return strangePrinter(s, 0, n - 1, mem);
  }

  // Recursive helper method for strangePrinter
  private int strangePrinter(String s, int i, int j, int[][] mem) {
    if (i > j)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    // Print s[i].
    mem[i][j] = strangePrinter(s, i + 1, j, mem) + 1;

    for (int k = i + 1; k <= j; k++)
      if (s.charAt(k) == s.charAt(i))
        mem[i][j] = Math.min(mem[i][j], strangePrinter(s, i, k - 1, mem) + //
                                            strangePrinter(s, k + 1, j, mem));

    return mem[i][j];
  }
}
