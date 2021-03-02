class Solution {
  public int numMusicPlaylists(int N, int L, int K) {
    this.N = N;
    this.K = K;

    // dp[i][j] := # of playlists with i songs and j different songs
    dp = new long[L + 1][N + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));

    return (int) playlists(L, N);
  }

  private static final int kMod = (int) 1e9 + 7;
  private int N;
  private int K;
  private long[][] dp;

  private long playlists(int i, int j) {
    if (i == 0)
      return j == 0 ? 1 : 0;
    if (j == 0)
      return 0;
    if (dp[i][j] >= 0)
      return dp[i][j];

    dp[i][j] = playlists(i - 1, j - 1) * (N - (j - 1)); // last song is new
    dp[i][j] += playlists(i - 1, j) * Math.max(0, j - K); // last song is old
    return dp[i][j] %= kMod;
  }
}
