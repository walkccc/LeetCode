class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    const int n = points[0].size();
    // dp[j] := the maximum number of points you can have if points[i][j] is the
    // most recent cell you picked
    vector<long> dp(n);

    for (const vector<int>& row : points) {
      vector<long> leftToRight(n);
      long runningMax = 0;

      for (int j = 0; j < n; ++j) {
        runningMax = max(runningMax - 1, dp[j]);
        leftToRight[j] = runningMax;
      }

      vector<long> rightToLeft(n);
      runningMax = 0;

      for (int j = n - 1; j >= 0; --j) {
        runningMax = max(runningMax - 1, dp[j]);
        rightToLeft[j] = runningMax;
      }

      for (int j = 0; j < n; ++j)
        dp[j] = max(leftToRight[j], rightToLeft[j]) + row[j];
    }

    return ranges::max(dp);
  }
};
