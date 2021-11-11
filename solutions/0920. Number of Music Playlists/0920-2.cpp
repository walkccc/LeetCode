class Solution {
 public:
  int numMusicPlaylists(int N, int L, int K) {
    constexpr int kMod = 1e9 + 7;

    // dp[i][j] := # of playlists with i songs and j different songs
    vector<vector<long>> dp(L + 1, vector<long>(N + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= L; ++i)
      for (int j = 1; j <= N; ++j) {
        dp[i][j] += dp[i - 1][j - 1] * (N - (j - 1));  // last song is new
        dp[i][j] += dp[i - 1][j] * max(0, j - K);      // last song is old
        dp[i][j] %= kMod;
      }

    return dp[L][N];
  }
};
