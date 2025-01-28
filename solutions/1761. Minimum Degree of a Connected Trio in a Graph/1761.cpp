class Solution {
 public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    int ans = INT_MAX;
    vector<unordered_set<int>> graph(n);
    vector<int> degrees(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0] - 1;
      const int v = edge[1] - 1;
      // Store the mapping from `min(u, v)` to `max(u, v)` to speed up.
      graph[min(u, v)].insert(max(u, v));
      ++degrees[u];
      ++degrees[v];
    }

    for (int u = 0; u < n; ++u)
      for (const int v : graph[u])
        for (const int w : graph[u])
          if (graph[v].contains(w))
            ans = min(ans, degrees[u] + degrees[v] + degrees[w] - 6);

    return ans == INT_MAX ? -1 : ans;
  }
};
