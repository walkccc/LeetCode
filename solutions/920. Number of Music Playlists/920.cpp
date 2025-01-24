class Solution {
 public:
  int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<long>> mem(goal + 1, vector<long>(n + 1, -1));
    return numMusicPlaylists(n, k, goal, n, mem);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the number of playlists with i songs and j different songs.
  long numMusicPlaylists(int n, int k, int i, int j,
                         vector<vector<long>>& mem) {
    if (i == 0)
      return j == 0;
    if (j == 0)
      return 0;
    if (mem[i][j] >= 0)
      return mem[i][j];

    // The last song is new.
    mem[i][j] = numMusicPlaylists(n, k, i - 1, j - 1, mem) * (n - (j - 1));
    // The last song is old.
    mem[i][j] += numMusicPlaylists(n, k, i - 1, j, mem) * max(0, j - k);
    return mem[i][j] %= kMod;
  }
};
