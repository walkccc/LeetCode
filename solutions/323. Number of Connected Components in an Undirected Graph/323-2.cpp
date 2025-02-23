class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      if (seen.insert(i).second) {
        dfs(graph, i, seen);
        ++ans;
      }

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, unordered_set<int>& seen) {
    for (const int v : graph[u])
      if (seen.insert(v).second)
        dfs(graph, v, seen);
  }
};
