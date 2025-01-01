class Solution {
  public int minOperations(int[][] grid, int x) {
    final int m = grid.length;
    final int n = grid[0].length;

    int[] A = new int[m * n];
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        A[i * n + j] = grid[i][j];
    if (Arrays.stream(A).anyMatch(a -> (a - A[0]) % x != 0))
      return -1;

    int ans = 0;

    Arrays.sort(A);

    for (final int a : A)
      ans += Math.abs(a - A[A.length / 2]) / x;

    return ans;
  }
}
