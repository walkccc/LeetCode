class Solution {
 public:
  int numberOfWays(int n, int m, int k, vector<int>& source,
                   vector<int>& dest) {
    constexpr int kMod = 1'000'000'007;
    // the number of ways of `source` to `dest` using steps so far
    int ans = source[0] == dest[0] && source[1] == dest[1];
    // the number of ways of `source` to dest's row using steps so far
    int row = source[0] == dest[0] && source[1] != dest[1];
    // the number of ways of `source` to dest's col using steps so far
    int col = source[0] != dest[0] && source[1] == dest[1];
    // the number of ways of `source` to others using steps so far
    int others = source[0] != dest[0] && source[1] != dest[1];

    for (int i = 0; i < k; ++i) {
      const int nextAns = (row + col) % kMod;
      const int nextRow = static_cast<int>((ans * (m - 1L) +  // -self
                                            row * (m - 2L) +  //-self, -center
                                            others) %
                                           kMod);
      const int nextCol = static_cast<int>((ans * (n - 1L) +  // -self
                                            col * (n - 2L) +  // -self, -center
                                            others) %
                                           kMod);
      const int nextOthers =
          static_cast<int>((row * (n - 1L) +              // -self
                            col * (m - 1L) +              // -self
                            others * (m + n - 1 - 3L)) %  // -self, -row, -col
                           kMod);
      ans = nextAns;
      row = nextRow;
      col = nextCol;
      others = nextOthers;
    }

    return ans;
  }
};
