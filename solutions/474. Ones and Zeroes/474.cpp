class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    // available
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (const string& s : strs) {
      const int zeros = ranges::count(s, '0');
      const int ones = s.length() - zeros;
      for (int i = m; i >= zeros; --i)
        for (int j = n; j >= ones; --j)
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }

    return dp[m][n];
  }
};
