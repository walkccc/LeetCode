class Solution {
  public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
    final int m = rowSum.length;
    final int n = colSum.length;
    int[][] ans = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans[i][j] = Math.min(rowSum[i], colSum[j]);
        rowSum[i] -= ans[i][j];
        colSum[j] -= ans[i][j];
      }

    return ans;
  }
}
