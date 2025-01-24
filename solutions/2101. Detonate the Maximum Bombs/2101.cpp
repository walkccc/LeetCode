class Solution {
 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    const int n = bombs.size();
    size_t ans = 0;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        const long ri = bombs[i][2];
        if (ri * ri >= squaredDist(bombs, i, j))
          graph[i].push_back(j);
      }
    }

    for (int i = 0; i < n; ++i) {
      unordered_set<int> seen{i};
      dfs(graph, i, seen);
      ans = max(ans, seen.size());
    }

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, unordered_set<int>& seen) {
    for (const int v : graph[u]) {
      if (seen.contains(v))
        continue;
      seen.insert(v);
      dfs(graph, v, seen);
    }
  }

  long squaredDist(const vector<vector<int>>& bombs, int i, int j) {
    return static_cast<long>(bombs[i][0] - bombs[j][0]) *
               (bombs[i][0] - bombs[j][0]) +
           static_cast<long>(bombs[i][1] - bombs[j][1]) *
               (bombs[i][1] - bombs[j][1]);
  }
};
