class Solution {
 public:
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges,
                                   vector<vector<int>>& queries) {
    constexpr int kMax = 26;
    const int m = log2(n) + 1;
    vector<int> ans;
    vector<vector<pair<int, int>>> graph(n);
    // jump[i][j] := the node you reach after jumping 2^j from i
    vector<vector<int>> jump(n, vector<int>(m));
    // count[i][j] := the count of j from root to i, where 1 <= j <= 26
    vector<vector<int>> count(n);
    // depth[i] := the depth of i
    vector<int> depth(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    count[0] = vector<int>(kMax + 1);
    dfs(graph, 0, /*prev=*/-1, 0, jump, count, depth);

    // Calculate binary lifting.
    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        jump[i][j] = jump[jump[i][j - 1]][j - 1];

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      const int lca = getLCA(u, v, jump, depth);
      // the number of edges between (u, v).
      const int numEdges = depth[u] + depth[v] - 2 * depth[lca];
      // the maximum frequency of edges between (u, v)
      int maxFreq = 0;
      for (int j = 1; j <= kMax; ++j)
        maxFreq = max(maxFreq, count[u][j] + count[v][j] - 2 * count[lca][j]);
      ans.push_back(numEdges - maxFreq);
    }

    return ans;
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph, int u, int prev, int d,
           vector<vector<int>>& jump, vector<vector<int>>& count,
           vector<int>& depth) {
    if (prev != -1)
      jump[u][0] = prev;
    depth[u] = d;
    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      // Inherit the count from the parent.
      count[v] = count[u];
      // Add one to this edge.
      ++count[v][w];
      dfs(graph, v, u, d + 1, jump, count, depth);
    }
  }

  // Returns the lca(u, v) via Calculate binary lifting.
  int getLCA(int u, int v, const vector<vector<int>>& jump,
             const vector<int>& depth) {
    // v is always deeper than u.
    if (depth[u] > depth[v])
      return getLCA(v, u, jump, depth);
    // Jump v to the same height of u.
    for (int j = 0; j < jump[0].size(); ++j)
      if (depth[v] - depth[u] >> j & 1)
        v = jump[v][j];
    if (u == v)
      return u;
    // Jump u and v to the node right below the lca.
    for (int j = jump[0].size() - 1; j >= 0; --j)
      if (jump[u][j] != jump[v][j]) {
        u = jump[u][j];
        v = jump[v][j];
      }
    return jump[v][0];
  }
};
