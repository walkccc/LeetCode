class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    // dp[i][j] := the maximum size of the subset given i 0s and j 1s are
    // available
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (const string& s : strs) {
      const int count0 = ranges::count(s, '0');
      const int count1 = s.length() - count0;
      for (int i = m; i >= count0; --i)
        for (int j = n; j >= count1; --j)
          dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
    }

    return dp[m][n];
  }
};
