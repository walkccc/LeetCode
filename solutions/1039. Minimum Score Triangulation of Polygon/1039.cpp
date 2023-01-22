class Solution {
 public:
  int minScoreTriangulation(vector<int>& A) {
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

    for (int j = 2; j < A.size(); ++j)
      for (int i = j - 2; i >= 0; --i) {
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
      }

    return dp[0][A.size() - 1];
  }
};
