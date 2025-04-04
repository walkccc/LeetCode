class Solution {
  public int numMusicPlaylists(int n, int goal, int k) {
    final int MOD = 1_000_000_007;
    // dp[i][j] := the number of playlists with i songs and j different songs
    long[][] dp = new long[goal + 1][n + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= goal; ++i)
      for (int j = 1; j <= n; ++j) {
        dp[i][j] += dp[i - 1][j - 1] * (n - (j - 1));  // The last song is new.
        dp[i][j] += dp[i - 1][j] * Math.max(0, j - k); // The last song is old.
        dp[i][j] %= MOD;
      }

    return (int) dp[goal][n];
  }
}
