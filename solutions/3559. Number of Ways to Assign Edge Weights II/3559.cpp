class Solution {
 public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                vector<vector<int>>& queries) {
    const int n = edges.size() + 1;
    vector<int> ans;
    vector<int> depth(n + 1);
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> parent(kLog, vector<int>(n + 1, -1));

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(1, -1, graph, parent, depth);

    for (int k = 1; k < kLog; ++k)
      for (int v = 1; v <= n; ++v)
        if (parent[k - 1][v] != -1)
          parent[k][v] = parent[k - 1][parent[k - 1][v]];

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      if (u == v) {
        ans.push_back(0);
      } else {
        const int a = lca(u, v, parent, depth);
        const int d = depth[u] + depth[v] - 2 * depth[a];
        ans.push_back(modPow(2, d - 1));
      }
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  static constexpr int kLog = 17;  // since 2^17 > 1e5

  void dfs(int u, int p, const vector<vector<int>>& graph,
           vector<vector<int>>& parent, vector<int>& depth) {
    parent[0][u] = p;
    for (const int v : graph[u])
      if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u, graph, parent, depth);
      }
  }

  int lca(int u, int v, const vector<vector<int>>& parent,
          const vector<int>& depth) {
    if (depth[u] < depth[v])
      swap(u, v);

    for (int k = kLog - 1; k >= 0; --k)
      if (parent[k][u] != -1 && depth[parent[k][u]] >= depth[v])
        u = parent[k][u];

    if (u == v)
      return u;

    for (int k = kLog - 1; k >= 0; --k)
      if (parent[k][u] != -1 && parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }

    return parent[0][u];
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
