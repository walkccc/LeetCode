class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < n; ++i)
      if (seen.insert(i).second) {
        dfs(graph, i, seen);
        ++ans;
      }

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int node,
           unordered_set<int>& seen) {
    for (const int child : graph[node])
      if (seen.insert(child).second)
        dfs(graph, child, seen);
  }
};
