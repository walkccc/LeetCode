class Solution {
  public int getMoneyAmount(int n) {
    int[][] mem = new int[n + 1][n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    return getMoneyAmount(1, n, mem);
  }

  // Returns the minimum money you need to guarantee a win of picking i..j.
  private int getMoneyAmount(int i, int j, int[][] mem) {
    if (i >= j)
      return 0;
    if (mem[i][j] != Integer.MAX_VALUE)
      return mem[i][j];

    for (int k = i; k <= j; ++k)
      mem[i][j] = Math.min(mem[i][j], Math.max(getMoneyAmount(i, k - 1, mem), //
                                               getMoneyAmount(k + 1, j, mem)) +
                                          k);

    return mem[i][j];
  }
}
