class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    const int n = A.size();
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      int min = INT_MIN;
      for (int j = 1; j <= std::min(i, K); ++j) {
        min = max(min, A[i - j]);
        dp[i] = max(dp[i], dp[i - j] + min * j);
      }
    }

    return dp[n];
  }
};
