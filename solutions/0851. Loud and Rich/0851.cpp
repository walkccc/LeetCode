class Solution {
 public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    const int n = quiet.size();
    vector<int> ans(n, -1);
    vector<vector<int>> graph(n);

    for (const vector<int>& r : richer) {
      const int u = r[1];
      const int v = r[0];
      graph[u].push_back(v);
    }

    for (int i = 0; i < n; ++i)
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
