class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    const int n = points[0].size();
    // dp[j] := max # points you can have if points[i][j] is the most recent
    // cell you picked
    vector<long long> dp(n);

    for (const auto& row : points) {
      vector<long long> leftToRight(n);
      long long runningMax = 0;

      for (int j = 0; j < n; ++j) {
        runningMax = max(runningMax - 1, dp[j]);
        leftToRight[j] = runningMax;
      }

      vector<long long> rightToLeft(n);
      runningMax = 0;

      for (int j = n - 1; j >= 0; --j) {
        runningMax = max(runningMax - 1, dp[j]);
        rightToLeft[j] = runningMax;
      }

      for (int j = 0; j < n; ++j)
        dp[j] = max(leftToRight[j], rightToLeft[j]) + row[j];
    }

    return *max_element(begin(dp), end(dp));
  }
};
