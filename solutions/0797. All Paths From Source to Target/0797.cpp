class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> path{0};

    dfs(graph, 0, path, ans);

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int node, vector<int>& path,
           vector<vector<int>>& ans) {
    if (node == graph.size() - 1) {
      ans.push_back(path);
      return;
    }

    for (const int child : graph[node]) {
      path.push_back(child);
      dfs(graph, child, path, ans);
      path.pop_back();
    }
  }
};
