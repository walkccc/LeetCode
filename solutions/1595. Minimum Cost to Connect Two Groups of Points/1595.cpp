class Solution {
 public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    const int m = cost.size();
    const int n = cost[0].size();
    // dp[i][j] := the minimum cost to connect group1's points[i..n) with
    // group2's points in bitmask j
    dp.resize(m, vector<int>(1 << n, -1));
    // minCosts[j] := the minimum cost of connecting group2's point j
    vector<int> minCosts(n);

    for (int j = 0; j < n; ++j) {
      int minCostIndex = 0;
      for (int i = 1; i < m; ++i)
        if (cost[i][j] < cost[minCostIndex][j])
          minCostIndex = i;
      minCosts[j] = cost[minCostIndex][j];
    }

    return connect(cost, 0, 0, minCosts);
  }

 private:
  vector<vector<int>> dp;

  int connect(const vector<vector<int>>& cost, int i, int mask,
              const vector<int>& minCosts) {
    if (i == cost.size()) {
      // All the points in group 1 are connected, so greedily assign the
      // minimum cost for the unconnected points of group2.
      int res = 0;
      for (int j = 0; j < cost[0].size(); ++j)
        if ((mask >> j & 1) == 0)
          res += minCosts[j];
      return res;
    }
    if (dp[i][mask] != -1)
      return dp[i][mask];

    int res = INT_MAX;
    for (int j = 0; j < cost[0].size(); ++j)
      res =
          min(res, cost[i][j] + connect(cost, i + 1, mask | 1 << j, minCosts));
    return dp[i][mask] = res;
  }
};
