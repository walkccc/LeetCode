class Solution {
 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    int ans = 0;
    vector<vector<int>> graph(n);
    unordered_set<int> seen;

    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    function<void(int)> dfs = [&](int i) {
      for (const int neighbor : graph[i])
        if (seen.insert(neighbor).second)
          dfs(neighbor);
    };

    for (int i = 0; i < n; ++i)
      if (seen.insert(i).second) {
        dfs(i);
        ++ans;
      }

    return ans;
  }
};