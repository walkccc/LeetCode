class Solution {
 public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    vector<int> ans(quiet.size(), -1);
    vector<vector<int>> graph(quiet.size());

    for (const auto& edge : richer)
      graph[edge[1]].push_back(edge[0]);

    for (int i = 0; i < graph.size(); ++i)
      dfs(graph, i, quiet, ans);

    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& graph, int node, const vector<int>& quiet,
          vector<int>& ans) {
    if (ans[node] != -1)
      return ans[node];

    ans[node] = node;

    for (const int child : graph[node]) {
      const int res = dfs(graph, child, quiet, ans);
      if (quiet[res] < quiet[ans[node]])
        ans[node] = res;
    }

    return ans[node];
  }
};
