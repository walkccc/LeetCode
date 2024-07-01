class Solution {
 public:
  int longestLine(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    int ans = 0;
    // dp[i][j][0] := horizontal
    // dp[i][j][1] := vertical
    // dp[i][j][2] := diagonal
    // dp[i][j][3] := anti-diagonal
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4)));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1) {
          dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
          dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
          dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
          dp[i][j][3] = (i > 0 && j < n - 1) ? dp[i - 1][j + 1][3] + 1 : 1;
          ans = max(ans, ranges::max(dp[i][j]));
        }

    return ans;
  }
};
