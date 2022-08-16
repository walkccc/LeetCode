class Solution {
 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    // dp[k][i][prevColor] := min cost to paint houses[i..m) to k neighborhoods
    // w/ houses[i - 1]'s color = prevColor
    dp.resize(target + 1, vector<vector<int>>(m, vector<int>(n + 1)));

    // init: prevColor = 0 (virtual neighbor)
    const int c = minCost(houses, cost, m, n, target, 0, 0);
    return c == kMax ? -1 : c;
  }

 private:
  constexpr static int kMax = 1e6 + 1;
  vector<vector<vector<int>>> dp;

  int minCost(const vector<int>& houses, const vector<vector<int>>& cost,
              const int& m, const int& n, int k, int i, int prevColor) {
    if (i == m || k < 0)
      return k == 0 ? 0 : kMax;
    if (dp[k][i][prevColor] > 0)
      return dp[k][i][prevColor];
    if (houses[i] > 0)  // painted last year
      return minCost(houses, cost, m, n, k - (prevColor != houses[i]), i + 1,
                     houses[i]);

    int ans = kMax;

    // try to paint houses[i] with each color in 1..n
    for (int color = 1; color <= n; ++color)
      ans = min(ans, cost[i][color - 1] + minCost(houses, cost, m, n,
                                                  k - (prevColor != color),
                                                  i + 1, color));

    return dp[k][i][prevColor] = ans;
  }
};
