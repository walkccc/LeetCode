class Solution {
  public int findLength(int[] A, int[] B) {
    final int m = A.length;
    final int n = B.length;

    int ans = 0;
    // dp[i][j] := max length of A[i:] and B[j:]
    int[][] dp = new int[m + 1][n + 1];

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        if (A[i] == B[j]) {
          dp[i][j] = dp[i + 1][j + 1] + 1;
          ans = Math.max(ans, dp[i][j]);
        }

    return ans;
  }
}
