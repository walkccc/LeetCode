class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    long long ans = 0;
    vector<vector<int>> graph(n);
    vector<bool> seen(n);
    int unreached = n;

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
      const int reached = dfs(graph, i, seen);
      unreached -= reached;
      ans += static_cast<long long>(unreached) * reached;
    }
    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, vector<bool>& seen) {
    if (seen[u])
      return 0;
    seen[u] = true;
    return accumulate(
        begin(graph[u]), end(graph[u]), 1,
        [&](int subtotal, int v) { return subtotal + dfs(graph, v, seen); });
  }
};
