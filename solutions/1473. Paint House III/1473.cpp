class Solution {
 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    vector<vector<vector<int>>> mem(target + 1,
                                    vector<vector<int>>(m, vector<int>(n + 1)));
    // Initialize `prevColor` to 0 (the virtual neighbor).
    const int c = minCost(houses, cost, m, n, target, 0, 0, mem);
    return c == kMax ? -1 : c;
  }

 private:
  static constexpr int kMax = 1'000'001;

  // Returns the minimum cost to paint houses[i..m) into k neighborhoods, where
  // there are houses[i - 1] colors = prevColor.
  int minCost(const vector<int>& houses, const vector<vector<int>>& cost,
              const int& m, const int& n, int k, int i, int prevColor,
              vector<vector<vector<int>>>& mem) {
    if (i == m || k < 0)
      return k == 0 ? 0 : kMax;
    if (mem[k][i][prevColor] > 0)
      return mem[k][i][prevColor];
    if (houses[i] > 0)  // The house was painted last year.
      return minCost(houses, cost, m, n, k - (prevColor != houses[i]), i + 1,
                     houses[i], mem);

    int res = kMax;

    // Try to paint the houses[i] with each color in 1..n.
    for (int color = 1; color <= n; ++color)
      res = min(res, cost[i][color - 1] + minCost(houses, cost, m, n,
                                                  k - (prevColor != color),
                                                  i + 1, color, mem));

    return mem[k][i][prevColor] = res;
  }
};
