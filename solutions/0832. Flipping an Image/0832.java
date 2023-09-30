class Solution {
  public int[][] flipAndInvertImage(int[][] A) {
    final int n = A.length;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < (n + 1) / 2; ++j) {
        final int temp = A[i][j];
        A[i][j] = A[i][n - j - 1] ^ 1;
        A[i][n - j - 1] = temp ^ 1;
      }

    return A;
  }
}
