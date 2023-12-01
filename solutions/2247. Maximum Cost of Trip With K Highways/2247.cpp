class Solution {
 public:
  int maximumCost(int n, vector<vector<int>>& highways, int k) {
    if (k + 1 > n)
      return -1;

    int ans = -1;
    // dp[u][mask] := the maximum cost of trip starting from u, where `mask`
    // represents the visited cities
    dp.resize(n, vector<int>(1 << n, -1));
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& h : highways) {
      const int u = h[0];
      const int v = h[1];
      const int w = h[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i)
      ans = max(ans, maximumCost(graph, i, 1 << i, k));

    return ans;
  }

 private:
  vector<vector<int>> dp;

  int maximumCost(const vector<vector<pair<int, int>>>& graph, int u, int mask,
                  int k) {
    if (__builtin_popcount(mask) == k + 1)
      return 0;
    if (dp[u][mask] != -1)
      return dp[u][mask];

    int ans = -1;
    for (const auto& [v, w] : graph[u]) {
      if (mask >> v & 1)
        continue;
      const int res = maximumCost(graph, v, mask | 1 << v, k);
      if (res != -1)
        ans = max(ans, w + res);
    }
    return dp[u][mask] = ans;
  }
};
