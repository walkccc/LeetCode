class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    return dfs(graph, 0, vector<bool>(n), hasApple);
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, vector<bool>&& seen,
          const vector<bool>& hasApple) {
    seen[u] = true;
    int totalCost = 0;

    for (const int v : graph[u]) {
      if (seen[v])
        continue;
      const int cost = dfs(graph, v, std::move(seen), hasApple);
      if (cost > 0 || hasApple[v])
        totalCost += cost + 2;
    }

    return totalCost;
  }
};
