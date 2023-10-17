class Solution {
 public:
  int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges,
                         int maxTime) {
    const int n = values.size();
    int ans = 0;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> seen(n);
    seen[0] = 1;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int time = edge[2];
      graph[u].emplace_back(v, time);
      graph[v].emplace_back(u, time);
    }

    dfs(graph, values, 0, values[0], maxTime, seen, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph,
           const vector<int>& values, int u, int quality, int remainingTime,
           vector<int>& seen, int& ans) {
    if (u == 0)
      ans = max(ans, quality);
    for (const auto& [v, time] : graph[u]) {
      if (time > remainingTime)
        continue;
      const int newQuality = quality + values[v] * (seen[v] == 0);
      ++seen[v];
      dfs(graph, values, v, newQuality, remainingTime - time, seen, ans);
      --seen[v];
    }
  }
};
