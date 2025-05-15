class Solution {
  public long gridGame(int[][] grid) {
    final int n = grid[0].length;
    long ans = Long.MAX_VALUE;
    long sumRow0 = Arrays.stream(grid[0]).asLongStream().sum();
    long sumRow1 = 0;

    for (int i = 0; i < n; ++i) {
      sumRow0 -= grid[0][i];
      ans = Math.min(ans, Math.max(sumRow0, sumRow1));
      sumRow1 += grid[1][i];
    }

    return ans;
  }
}
