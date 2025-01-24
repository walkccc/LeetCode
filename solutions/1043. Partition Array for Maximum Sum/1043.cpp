class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    const int n = arr.size();
    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      int mx = INT_MIN;
      for (int j = 1; j <= min(i, k); ++j) {
        mx = max(mx, arr[i - j]);
        dp[i] = max(dp[i], dp[i - j] + mx * j);
      }
    }

    return dp[n];
  }
};
