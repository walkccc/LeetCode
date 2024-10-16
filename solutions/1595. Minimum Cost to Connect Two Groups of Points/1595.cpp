class Solution {
 public:
  int connectTwoGroups(vector<vector<int>>& cost) {
    const int m = cost.size();
    const int n = cost[0].size();
    vector<vector<int>> mem(m, vector<int>(1 << n, INT_MAX));
    // minCosts[j] := the minimum cost of connecting group2's point j
    vector<int> minCosts(n);

    for (int j = 0; j < n; ++j) {
      int minCostIndex = 0;
      for (int i = 1; i < m; ++i)
        if (cost[i][j] < cost[minCostIndex][j])
          minCostIndex = i;
      minCosts[j] = cost[minCostIndex][j];
    }

    return connectTwoGroups(cost, 0, 0, minCosts, mem);
  }

 private:
  // Returns the minimum cost to connect group1's points[i..n) with group2's
  // points, where `mask` is the bitmask of the connected points in group2.
  int connectTwoGroups(const vector<vector<int>>& cost, int i, int mask,
                       const vector<int>& minCosts, vector<vector<int>>& mem) {
    if (i == cost.size()) {
      // All the points in group 1 are connected, so greedily assign the
      // minimum cost for the unconnected points of group2.
      int res = 0;
      for (int j = 0; j < cost[0].size(); ++j)
        if ((mask >> j & 1) == 0)
          res += minCosts[j];
      return res;
    }
    if (mem[i][mask] != INT_MAX)
      return mem[i][mask];

    for (int j = 0; j < cost[0].size(); ++j)
      mem[i][mask] =
          min(mem[i][mask],
              cost[i][j] +
                  connectTwoGroups(cost, i + 1, mask | 1 << j, minCosts, mem));

    return mem[i][mask];
  }
};
