class Solution {
  public boolean checkValid(int[][] matrix) {
    final int n = matrix.length;

    for (int i = 0; i < n; ++i) {
      Set<Integer> row = new HashSet<>();
      Set<Integer> col = new HashSet<>();
      for (int j = 0; j < n; ++j) {
        row.add(matrix[i][j]);
        col.add(matrix[j][i]);
      }
      if (Math.min(row.size(), col.size()) < n)
        return false;
    }

    return true;
  }
}
