class Solution {
 public:
  int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    const int n = coins.size();
    vector<vector<int>> graph(n);
    vector<vector<int>> mem(n, vector<int>(kMaxHalved + 1, -1));

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    return dfs(graph, 0, /*prev=*/-1, coins, k, /*halved=*/0, mem);
  }

 private:
  static constexpr int kMaxCoin = 10000;
  static constexpr int kMaxHalved = 13;  // log2(kMaxCoin) = 13

  int dfs(const vector<vector<int>>& graph, int u, int prev,
          const vector<int>& coins, int k, int halved,
          vector<vector<int>>& mem) {
    // All the children will be 0, so no need to explore.
    if (halved > kMaxHalved)
      return 0;
    if (mem[u][halved] != -1)
      return mem[u][halved];

    const int val = coins[u] / (1 << halved);
    int takeAll = val - k;
    int takeHalf = floor(val / 2.0);

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      takeAll += dfs(graph, v, u, coins, k, halved, mem);
      takeHalf += dfs(graph, v, u, coins, k, halved + 1, mem);
    }

    return mem[u][halved] = max(takeAll, takeHalf);
  }
};
