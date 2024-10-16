class Solution {
  public int numMusicPlaylists(int n, int goal, int k) {
    long[][] mem = new long[goal + 1][n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, -1));
    return (int) numMusicPlaylists(n, k, goal, n, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of playlists with i songs and j different songs.
  private long numMusicPlaylists(int n, int k, int i, int j, long[][] mem) {
    if (i == 0)
      return j == 0 ? 1 : 0;
    if (j == 0)
      return 0;
    if (mem[i][j] >= 0)
      return mem[i][j];

    // The last song is new.
    mem[i][j] = numMusicPlaylists(n, k, i - 1, j - 1, mem) * (n - (j - 1));
    // The last song is old.
    mem[i][j] += numMusicPlaylists(n, k, i - 1, j, mem) * Math.max(0, j - k);
    return mem[i][j] %= kMod;
  }
}
