class Solution {
 public:
  int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
    constexpr int kMax = 1'000'000;
    vector<vector<pair<int, int>>> reversedGraph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      reversedGraph[v].push_back({u, w});
    }

    int l = 1;
    int r = kMax + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (dfs(reversedGraph, 0, m, vector<bool>(n)) == n)
        r = m;
      else
        l = m + 1;
    }

    return l == (kMax + 1) ? -1 : l;
  }

 private:
  // Returns the number of nodes reachable from u with weight <= m.
  int dfs(const vector<vector<pair<int, int>>>& reversedGraph, int u,
          int maxWeight, vector<bool>&& seen) {
    int res = 1;
    seen[u] = true;
    for (const auto& [v, w] : reversedGraph[u]) {
      if (w > maxWeight || seen[v])
        continue;
      res += dfs(reversedGraph, v, maxWeight, std::move(seen));
    }
    return res;
  }
};
