class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    const int n = cost.size();
    // dp[i][j] := the minimum cost to paint j walls by the painters[i..n)
    dp.resize(n, vector<int>(n + 1));
    return paintWalls(cost, time, 0, time.size());
  }

 private:
  static constexpr int kMax = 500'000'000;
  vector<vector<int>> dp;

  int paintWalls(const vector<int>& cost, const vector<int>& time, int i,
                 int walls) {
    if (walls <= 0)
      return 0;
    if (i == cost.size())
      return kMax;
    if (dp[i][walls] > 0)
      return dp[i][walls];
    const int pick =
        cost[i] + paintWalls(cost, time, i + 1, walls - time[i] - 1);
    const int skip = paintWalls(cost, time, i + 1, walls);
    return dp[i][walls] = min(pick, skip);
  }
};
