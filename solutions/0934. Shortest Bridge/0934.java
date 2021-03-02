class Solution {
  public int shortestBridge(int[][] A) {
    markAsTwo(A);

    for (int color = 2;; ++color)
      for (int i = 0; i < A.length; ++i)
        for (int j = 0; j < A[0].length; ++j)
          if (A[i][j] == color)
            if (expand(A, i + 1, j, color) || expand(A, i - 1, j, color) ||
                expand(A, i, j + 1, color) || expand(A, i, j - 1, color))
              return color - 2;
  }

  // mark one group to 2s by DFS
  private void markAsTwo(int[][] A) {
    for (int i = 0; i < A.length; ++i)
      for (int j = 0; j < A[0].length; ++j)
        if (A[i][j] == 1) {
          markAsTwo(A, i, j);
          return;
        }
  }

  private void markAsTwo(int[][] A, int i, int j) {
    if (i < 0 || i == A.length || j < 0 || j == A[0].length)
      return;
    if (A[i][j] != 1)
      return;

    A[i][j] = 2;
    markAsTwo(A, i + 1, j);
    markAsTwo(A, i - 1, j);
    markAsTwo(A, i, j + 1);
    markAsTwo(A, i, j - 1);
  }

  // expand from colors' group to 1s' group
  private boolean expand(int[][] A, int i, int j, int color) {
    if (i < 0 || i == A.length || j < 0 || j == A[0].length)
      return false;
    if (A[i][j] == 0)
      A[i][j] = color + 1;
    return A[i][j] == 1; // we touch the 1s' group!
  }
}
