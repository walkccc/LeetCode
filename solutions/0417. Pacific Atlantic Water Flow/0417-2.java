class Solution {
  public List<List<Integer>> pacificAtlantic(int[][] matrix) {
    if (matrix.length == 0)
      return new ArrayList<>();

    final int m = matrix.length;
    final int n = matrix[0].length;

    List<List<Integer>> ans = new ArrayList<>();
    boolean[][] seenP = new boolean[m][n];
    boolean[][] seenA = new boolean[m][n];

    for (int i = 0; i < m; ++i) {
      dfs(matrix, i, 0, 0, seenP);
      dfs(matrix, i, n - 1, 0, seenA);
    }

    for (int j = 0; j < n; ++j) {
      dfs(matrix, 0, j, 0, seenP);
      dfs(matrix, m - 1, j, 0, seenA);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (seenP[i][j] && seenA[i][j])
          ans.add(new ArrayList<>(Arrays.asList(i, j)));

    return ans;
  }

  private void dfs(final int[][] matrix, int i, int j, int h, boolean[][] seen) {
    if (i < 0 || i == matrix.length || j < 0 || j == matrix[0].length)
      return;
    if (seen[i][j] || matrix[i][j] < h)
      return;

    seen[i][j] = true;
    dfs(matrix, i + 1, j, matrix[i][j], seen);
    dfs(matrix, i - 1, j, matrix[i][j], seen);
    dfs(matrix, i, j + 1, matrix[i][j], seen);
    dfs(matrix, i, j - 1, matrix[i][j], seen);
  }
}
