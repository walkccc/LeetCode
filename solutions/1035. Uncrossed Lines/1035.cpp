class Solution {
 public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    const int m = A.size();
    const int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1
                                        : max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
};
