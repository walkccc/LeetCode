class Solution {
 public:
  int countPyramids(vector<vector<int>>& grid) {
    int ans = count(grid);
    reverse(begin(grid), end(grid));
    ans += count(grid);
    return ans;
  }

 private:
  // dp[i][j] := max height of the pyramid for which it is the apex
  int count(vector<vector<int>> dp) {
    int ans = 0;
    for (int i = dp.size() - 2; i >= 0; --i)
      for (int j = 1; j + 1 < dp[0].size(); ++j)
        if (dp[i][j] == 1) {
          dp[i][j] =
              min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
          ans += dp[i][j] - 1;
        }
    return ans;
  }
};
