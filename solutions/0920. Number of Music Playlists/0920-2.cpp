class Solution {
 public:
  int numMusicPlaylists(int n, int goal, int k) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][j] := # of playlists with i songs and j different songs
    vector<vector<long>> dp(goal + 1, vector<long>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= goal; ++i)
      for (int j = 1; j <= n; ++j) {
        dp[i][j] += dp[i - 1][j - 1] * (n - (j - 1));  // last song is new
        dp[i][j] += dp[i - 1][j] * max(0, j - k);      // last song is old
        dp[i][j] %= kMod;
      }

    return dp[goal][n];
  }
};
