class Solution {
 public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    const int n = floor.length();
    // dp[i][j] := min # of visible white tiles of floor[i:]
    // after covering at most j carpets
    vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1));

    for (int i = n - 1; i >= 0; --i)
      dp[i][0] = floor[i] - '0' + dp[i + 1][0];

    for (int i = n - 1; i >= 0; --i)
      for (int j = 1; j <= numCarpets; ++j) {
        const int cover = i + carpetLen < n ? dp[i + carpetLen][j - 1] : 0;
        const int skip = floor[i] - '0' + dp[i + 1][j];
        dp[i][j] = min(cover, skip);
      }

    return dp[0][numCarpets];
  }
};
