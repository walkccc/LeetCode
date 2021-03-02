class Solution {
  public int findLength(int[] A, int[] B) {
    final int m = A.length;
    final int n = B.length;

    int ans = 0;
    int[] dp = new int[n + 1];

    for (int i = m - 1; i >= 0; --i)
      for (int j = 0; j < n; ++j) { // the order is important
        dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0;
        ans = Math.max(ans, dp[j]);
      }

    return ans;
  }
}
