class Solution {
 public:
  int numMusicPlaylists(int N, int L, int K) {
    this->N = N;
    this->K = K;

    // dp[i][j] := # of playlists with i songs and j different songs
    dp.resize(L + 1, vector<long>(N + 1, -1));

    return playlists(L, N);
  }

 private:
  constexpr static int kMod = 1e9 + 7;
  int N;
  int K;
  vector<vector<long>> dp;

  long playlists(int i, int j) {
    if (i == 0)
      return j == 0;
    if (j == 0)
      return 0;
    if (dp[i][j] >= 0)
      return dp[i][j];

    dp[i][j] = playlists(i - 1, j - 1) * (N - (j - 1));  // last song is new
    dp[i][j] += playlists(i - 1, j) * max(0, j - K);     // last song is old
    return dp[i][j] %= kMod;
  }
};
