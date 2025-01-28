class Solution {
 public:
  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                             int signalSpeed) {
    const int n = edges.size() + 1;
    vector<int> ans;
    vector<vector<pair<int, int>>> tree(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      tree[u].emplace_back(v, w);
      tree[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i)
      ans.push_back(connectablePairsRootedAt(tree, i, signalSpeed));

    return ans;
  }

 private:
  // Returns the number of server pairs that are connectable through the server
  // `u`.
  int connectablePairsRootedAt(const vector<vector<pair<int, int>>>& tree,
                               int u, int signalSpeed) {
    int pairs = 0;
    int count = 0;
    for (const auto& [v, w] : tree[u]) {
      const int childCount = dfs(tree, v, u, w, signalSpeed);
      pairs += count * childCount;
      count += childCount;
    }
    return pairs;
  }

  // Returns the number of servers that are connectable throught the server `u`
  // (dist % signalSpeed == 0).
  int dfs(const vector<vector<pair<int, int>>>& tree, int u, int prev, int dist,
          int signalSpeed) {
    int count = 0;
    for (const auto& [v, w] : tree[u])
      if (v != prev)
        count += dfs(tree, v, u, dist + w, signalSpeed);
    return (dist % signalSpeed == 0 ? 1 : 0) + count;
  }
};
