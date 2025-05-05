class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    const int n = cost.size();
    vector<vector<int>> mem(n, vector<int>(n + 1));
    return paintWalls(cost, time, 0, time.size(), mem);
  }

 private:
  static constexpr int kMax = 500'000'000;

  // Returns the minimum cost to paint j walls by painters[i..n).
  int paintWalls(const vector<int>& cost, const vector<int>& time, int i,
                 int walls, vector<vector<int>>& mem) {
    if (walls <= 0)
      return 0;
    if (i == cost.size())
      return kMax;
    if (mem[i][walls] > 0)
      return mem[i][walls];
    const int pick =
        cost[i] + paintWalls(cost, time, i + 1, walls - time[i] - 1, mem);
    const int skip = paintWalls(cost, time, i + 1, walls, mem);
    return mem[i][walls] = min(pick, skip);
  }
};
