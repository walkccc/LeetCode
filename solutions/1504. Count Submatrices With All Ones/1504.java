class Solution {
  public int numSubmat(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = 0;

    for (int baseRow = 0; baseRow < m; ++baseRow) {
      int[] row = new int[n];
      Arrays.fill(row, 1);
      for (int i = baseRow; i < m; ++i) {
        for (int j = 0; j < n; ++j)
          row[j] &= mat[i][j];
        ans += count(row);
      }
    }

    return ans;
  }

  private int count(int[] row) {
    int ans = 0;
    int length = 0;

    for (final int a : row) {
      length = a == 0 ? 0 : length + 1;
      ans += length;
    }

    return ans;
  }
}
