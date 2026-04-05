class Solution {
 public:
  // Similar to 2846. Minimum Edge Weight Equilibrium Queries in a Tree
  vector<int> minimumWeight(vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
    const int n = edges.size() + 1;
    const int m = ceil(log2(n));
    vector<int> ans;
    vector<vector<pair<int, int>>> graph(n);
    // jump[i][j] := the 2^j-th ancestor of i
    vector<vector<int>> jump(n, vector<int>(m));
    // depth[i] := the depth of i
    vector<int> depth(n);
    // dist[i] := the distance from root to i
    vector<int> dist(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    dfs(graph, 0, /*prev=*/-1, jump, depth, dist);

    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        jump[i][j] = jump[jump[i][j - 1]][j - 1];

    for (const vector<int>& query : queries) {
      const int src1 = query[0];
      const int src2 = query[1];
      const int dest = query[2];
      ans.push_back((distance(src1, src2, jump, depth, dist) +
                     distance(src1, dest, jump, depth, dist) +
                     distance(src2, dest, jump, depth, dist)) /
                    2);
    }

    return ans;
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph, int u, int prev,
           vector<vector<int>>& jump, vector<int>& depth, vector<int>& dist) {
    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      jump[v][0] = u;
      depth[v] = depth[u] + 1;
      dist[v] = dist[u] + w;
      dfs(graph, v, u, jump, depth, dist);
    }
  }

  // Returns the lca(u, v) by binary jump.
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
    return jump[u][0];
  }

  // Returns the distance between u and v.
  int distance(int u, int v, const vector<vector<int>>& jump,
               const vector<int>& depth, const vector<int>& dist) {
    const int lca = getLCA(u, v, jump, depth);
    return dist[u] + dist[v] - 2 * dist[lca];
  }
};
