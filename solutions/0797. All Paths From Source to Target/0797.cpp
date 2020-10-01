class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> path{0};

    function<void(int)> dfs = [&](int node) {
      if (node == graph.size() - 1) {
        ans.push_back(path);
        return;
      }

      for (const int neighbor : graph[node]) {
        path.push_back(neighbor);
        dfs(neighbor);
        path.pop_back();
      }
    };

    dfs(0);

    return ans;
  }
};