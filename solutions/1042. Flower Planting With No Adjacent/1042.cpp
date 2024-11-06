class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    vector<int> ans(n);  // ans[i] := 1, 2, 3, or 4
    vector<vector<int>> graph(n);

    for (const vector<int>& path : paths) {
      const int u = path[0] - 1;
      const int v = path[1] - 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int u = 0; u < n; ++u) {
      int used = 0;
      for (const int v : graph[u])
        used |= 1 << ans[v];
      ans[u] = getFirstUnusedType(used);
    }

    return ans;
  }

 private:
  int getFirstUnusedType(int used) {
    for (int type = 1; type <= 4; ++type)
      if ((used >> type & 1) == 0)
        return type;
    throw;
  }
};
