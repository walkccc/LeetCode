class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    dfs(graph, 0, {0}, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (u == graph.size() - 1) {
      ans.push_back(path);
      return;
    }

    for (const int v : graph[u]) {
      path.push_back(v);
      dfs(graph, v, move(path), ans);
      path.pop_back();
    }
  }
};
