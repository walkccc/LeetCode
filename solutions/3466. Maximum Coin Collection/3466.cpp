class Solution {
 public:
  long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
    const int n = lane1.size();
    // dp[i][k] := the maximum number of coins at i-th mile with k switches
    vector<vector<long>> dp(n, vector<long>(3, LONG_MIN));
    dp[0][0] = lane1[0];
    dp[0][1] = lane2[0];

    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(0L, dp[i - 1][0]) + lane1[i];
      dp[i][1] = max({0L, dp[i - 1][0], dp[i - 1][1]}) + lane2[i];
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + lane1[i];
    }

    return accumulate(dp.begin(), dp.end(), LONG_MIN,
                      [](long acc, const vector<long>& row) {
      return max(acc, ranges::max(row));
    });
  }
};
