class Solution {
 public:
  int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    const int n = coins.size();
    vector<vector<int>> graph(n);
    dp.resize(n, vector<int>(kMaxHalved + 1, -1));

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    return dfs(graph, 0, /*prev=*/-1, coins, k, /*halved=*/0);
  }

 private:
  static constexpr int kMaxCoint = 10000;
  const int kMaxHalved = log2(kMaxCoint);  // 13
  vector<vector<int>> dp;

  int dfs(const vector<vector<int>>& graph, int u, int prev,
          const vector<int>& coins, int k, int halved) {
    // All the children will be 0, so no need to explore.
    if (halved > kMaxHalved)
      return 0;
    if (dp[u][halved] != -1)
      return dp[u][halved];

    const int val = coins[u] / (1 << halved);
    int takeAll = val - k;
    int takeHalf = floor(val / 2.0);

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      takeAll += dfs(graph, v, u, coins, k, halved);
      takeHalf += dfs(graph, v, u, coins, k, halved + 1);
    }

    return dp[u][halved] = max(takeAll, takeHalf);
  }
};
