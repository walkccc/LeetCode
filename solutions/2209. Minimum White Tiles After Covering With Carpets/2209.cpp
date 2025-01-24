class Solution {
 public:
  int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    vector<vector<int>> mem(floor.length() + 1,
                            vector<int>(numCarpets + 1, kMax));
    return minimumWhiteTiles(floor, 0, numCarpets, carpetLen, mem);
  }

 private:
  static constexpr int kMax = 1000;

  // Returns the minimum number of visible white tiles of floor[i..n) after
  // covering at most j carpets.
  int minimumWhiteTiles(const string& floor, int i, int j, int carpetLen,
                        vector<vector<int>>& mem) {
    if (j < 0)
      return kMax;
    if (i >= floor.length())
      return 0;
    if (mem[i][j] != kMax)
      return mem[i][j];
    return mem[i][j] = min(
               minimumWhiteTiles(floor, i + carpetLen, j - 1, carpetLen, mem),
               minimumWhiteTiles(floor, i + 1, j, carpetLen, mem) + floor[i] -
                   '0');
  }
};
