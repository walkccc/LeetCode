class Solution {
 public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    vector<int> ans(quiet.size(), -1);
    vector<vector<int>> graph(quiet.size());

    for (const auto& e : richer)
      graph[e[1]].push_back(e[0]);

    for (int i = 0; i < graph.size(); ++i)
      dfs(graph, i, quiet, ans);

    return ans;
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, const vector<int>& quiet,
          vector<int>& ans) {
    if (ans[u] != -1)
      return ans[u];

    ans[u] = u;

    for (const int v : graph[u]) {
      const int res = dfs(graph, v, quiet, ans);
      if (quiet[res] < quiet[ans[u]])
        ans[u] = res;
    }

    return ans[u];
  }
};
