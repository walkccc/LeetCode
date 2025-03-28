class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    int ans = INT_MAX;
    vector<vector<pair<int, int>>> graph(n);  // graph[u] := [(v, distance)]
    queue<int> q{{0}};
    vector<bool> seen(n);
    seen[0] = true;

    for (const vector<int>& r : roads) {
      const int u = r[0] - 1;
      const int v = r[1] - 1;
      const int distance = r[2];
      graph[u].emplace_back(v, distance);
      graph[v].emplace_back(u, distance);
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const auto& [v, d] : graph[u]) {
        ans = min(ans, d);
        if (seen[v])
          continue;
        q.push(v);
        seen[v] = true;
      }
    }

    return ans;
  }
};
