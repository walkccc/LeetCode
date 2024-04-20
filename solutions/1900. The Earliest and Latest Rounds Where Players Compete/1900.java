class Solution {
  public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    int[][][][] mem = new int[n + 1][n + 1][n + 1][2];
    return solve(firstPlayer, n - secondPlayer + 1, n, mem);
  }

  // Returns the (earliest, latest) pair, the first player is the l-th player
  // from the front, the second player is the r-th player from the end, and
  // there're k people.
  private int[] solve(int l, int r, int k, int[][][][] mem) {
    if (l == r)
      return new int[] {1, 1};
    if (l > r)
      return solve(r, l, k, mem);
    if (!Arrays.equals(mem[l][r][k], new int[] {0, 0}))
      return mem[l][r][k];

    int a = Integer.MAX_VALUE;
    int b = Integer.MIN_VALUE;

    // Enumerate all the possible positions.
    for (int i = 1; i <= l; ++i)
      for (int j = l - i + 1; j <= r - i; ++j) {
        if (i + j > (k + 1) / 2 || i + j < l + r - k / 2)
          continue;
        int[] res = solve(i, j, (k + 1) / 2, mem);
        a = Math.min(a, res[0] + 1);
        b = Math.max(b, res[1] + 1);
      }

    return mem[l][r][k] = new int[] {a, b};
  }
}
