class Solution {
 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    constexpr int kMax = 1000001;
    vector<vector<vector<int>>> memo(target + 1, vector<vector<int>>(m, vector<int>(n + 1)));

    // dp(k, i, c) := min cost to paint houses[i..m) to k neighborhoods
    // with houses[i - 1]'s color = prevColor
    function<int(int, int, int)> dp = [&](int k, int i, int prevColor) -> int {
      if (i == m || k < 0) return k == 0 ? 0 : kMax;
      int& ans = memo[k][i][prevColor];
      if (ans > 0) return ans;
      if (houses[i] != 0)  // painted last year
        return dp(k - (prevColor != houses[i]), i + 1, houses[i]);

      ans = kMax;

      // try to paint houses[i] with each color in 1..n
      for (int color = 1; color <= n; ++color)
        ans = min(ans, cost[i][color - 1] +
                           dp(k - (prevColor != color), i + 1, color));

      return ans;
    };

    // init: prevColor = 0 (virtual neighbor)
    const int minCost = dp(target, 0, 0);
    return minCost == kMax ? -1 : minCost;
  }
};