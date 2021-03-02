class Solution {
 public:
  int minKnightMoves(int x, int y) {
    return dp(abs(x), abs(y));
  }

 private:
  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  unordered_map<pair<int, int>, int, pairHash> memo;

  int dp(int x, int y) {
    if (x + y == 0)  // (0, 0)
      return 0;
    if (x + y == 2)  // (0, 2), (1, 1), (2, 0)
      return 2;
    if (memo.count({x, y}))
      return memo[{x, y}];

    return memo[{x, y}] = min(
      dp(abs(x - 2), abs(y - 1)),
      dp(abs(x - 1), abs(y - 2))) + 1;
  }
};
