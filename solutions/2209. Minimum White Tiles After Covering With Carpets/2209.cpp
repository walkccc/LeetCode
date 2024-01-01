class Solution {
 public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    // dp[i][j] := the minimum number of visible white tiles of floor[i..n)
    // after covering at most j carpets
    dp.resize(floor.length() + 1, vector<int>(numCarpets + 1, kMax));
    return minimumWhiteTiles(floor, 0, numCarpets, carpetLen);
  }

 private:
  static constexpr int kMax = 1000;
  vector<vector<int>> dp;

  int minimumWhiteTiles(const string& floor, int i, int j, int carpetLen) {
    if (j < 0)
      return kMax;
    if (i >= floor.length())
      return 0;
    if (dp[i][j] != kMax)
      return dp[i][j];
    return dp[i][j] = min(
               minimumWhiteTiles(floor, i + carpetLen, j - 1, carpetLen),
               minimumWhiteTiles(floor, i + 1, j, carpetLen) + floor[i] - '0');
  }
};
