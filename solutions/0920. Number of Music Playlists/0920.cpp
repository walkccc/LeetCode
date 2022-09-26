class Solution {
 public:
  int numMusicPlaylists(int n, int goal, int k) {
    this->n = n;
    this->k = k;
    // dp[i][j] := # of playlists with i songs and j different songs
    dp.resize(goal + 1, vector<long>(n + 1, -1));
    return playlists(goal, n);
  }

 private:
  constexpr static int kMod = 1'000'000'007;
  int n;
  int k;
  vector<vector<long>> dp;

  long playlists(int i, int j) {
    if (i == 0)
      return j == 0;
    if (j == 0)
      return 0;
    if (dp[i][j] >= 0)
      return dp[i][j];

    dp[i][j] = playlists(i - 1, j - 1) * (n - (j - 1));  // last song is new
    dp[i][j] += playlists(i - 1, j) * max(0, j - k);     // last song is old
    return dp[i][j] %= kMod;
  }
};
