class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);
    vector<bool> seen(n);

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    return dfs(graph, 0, seen, hasApple);
  }

 private:
  int dfs(const vector<vector<int>>& graph, int node, vector<bool>& seen,
          const vector<bool>& hasApple) {
    seen[node] = true;
    int totalCost = 0;

    for (const int child : graph[node]) {
      if (seen[child])
        continue;
      const int cost = dfs(graph, child, seen, hasApple);
      if (cost > 0 || hasApple[child])
        totalCost += cost + 2;
    }

    return totalCost;
  }
};
