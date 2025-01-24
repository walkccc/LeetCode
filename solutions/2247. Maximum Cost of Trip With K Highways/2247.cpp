class Solution {
 public:
  int maximumCost(int n, vector<vector<int>>& highways, int k) {
    if (k + 1 > n)
      return -1;

    int ans = -1;
    vector<vector<int>> mem(n, vector<int>(1 << n, -1));
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& h : highways) {
      const int u = h[0];
      const int v = h[1];
      const int w = h[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i)
      ans = max(ans, maximumCost(graph, i, 1 << i, k, mem));

    return ans;
  }

 private:
  // Returns the maximum cost of trip starting from u, where `mask` is the
  // bitmask of the visited cities.
  int maximumCost(const vector<vector<pair<int, int>>>& graph, int u,
                  unsigned mask, int k, vector<vector<int>>& mem) {
    if (popcount(mask) == k + 1)
      return 0;
    if (mem[u][mask] != -1)
      return mem[u][mask];

    int res = -1;
    for (const auto& [v, w] : graph[u]) {
      if (mask >> v & 1)
        continue;
      const int nextCost = maximumCost(graph, v, mask | 1 << v, k, mem);
      if (nextCost != -1)
        res = max(res, w + nextCost);
    }

    return mem[u][mask] = res;
  }
};
