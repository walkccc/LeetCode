class Solution {
 public:
  int minKnightMoves(int x, int y) {
    return dp(abs(x), abs(y));
  }

 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  unordered_map<pair<int, int>, int, PairHash> memo;

  int dp(int x, int y) {
    if (x + y == 0)  // (0, 0)
      return 0;
    if (x + y == 2)  // (0, 2), (1, 1), (2, 0)
      return 2;
    if (const auto it = memo.find({x, y}); it != memo.cend())
      return it->second;

    return memo[{x, y}] = 1 + min(dp(abs(x - 2), abs(y - 1)),  //
                                  dp(abs(x - 1), abs(y - 2)));
  }
};
