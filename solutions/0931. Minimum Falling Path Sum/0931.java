class Solution {
  public int minFallingPathSum(int[][] A) {
    final int n = A.length;

    for (int i = 1; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int min = Integer.MAX_VALUE;
        for (int k = Math.max(0, j - 1); k < Math.min(n, j + 2); ++k)
          min = Math.min(min, A[i - 1][k]);
        A[i][j] += min;
      }

    return Arrays.stream(A[n - 1]).min().getAsInt();
  }
}
