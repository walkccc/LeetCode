class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n);
    vector<vector<int>> graph(n);

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, -1, labels, ans);

    return ans;
  }

 private:
  vector<int> dfs(const vector<vector<int>>& graph, int u, int parent,
                  const string& labels, vector<int>& ans) {
    vector<int> count(26);  // count of letters down from this u

    for (const int v : graph[u]) {
      if (v == parent)
        continue;
      vector<int> childCount = dfs(graph, v, u, labels, ans);
      for (int i = 0; i < 26; ++i)
        count[i] += childCount[i];
    }

    ans[u] = ++count[labels[u] - 'a'];  // the u itself
    return count;
  }
};
