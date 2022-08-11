class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> ans(n);  // ans[i] := 1, 2, 3, or 4
    vector<vector<int>> graph(n);

    for (const auto& p : paths) {
      const int u = p[0] - 1;
      const int v = p[1] - 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
      vector<bool> used(5);
      for (const int v : graph[i])
        used[ans[v]] = true;
      for (int type = 1; type < 5; ++type)
        if (!used[type]) {
          ans[i] = type;
          break;
        }
    }

    return ans;
  }
};
