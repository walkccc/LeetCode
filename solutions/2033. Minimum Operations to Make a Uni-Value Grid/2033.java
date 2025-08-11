class Solution {
  public int minOperations(int[][] grid, int x) {
    final int m = grid.length;
    final int n = grid[0].length;
    int[] arr = new int[m * n];
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        arr[i * n + j] = grid[i][j];
    if (Arrays.stream(arr).anyMatch(a -> (a - arr[0]) % x != 0))
      return -1;

    int ans = 0;

    Arrays.sort(arr);

    for (final int a : arr)
      ans += Math.abs(a - arr[arr.length / 2]) / x;

    return ans;
  }
}
