class Solution {
  public int numMusicPlaylists(int N, int L, int K) {
    final int kMod = (int) 1e9 + 7;

    // dp[i][j] := # of playlists with i songs and j different songs
    long[][] dp = new long[L + 1][N + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= L; ++i)
      for (int j = 1; j <= N; ++j) {
        dp[i][j] += dp[i - 1][j - 1] * (N - (j - 1)); // last song is new
        dp[i][j] += dp[i - 1][j] * Math.max(0, j - K); // last song is old
        dp[i][j] %= kMod;
      }

    return (int) dp[L][N];
  }
}
