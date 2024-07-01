class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = graph.size();
    const int goal = (1 << n) - 1;

    int ans = 0;
    queue<pair<int, int>> q;  // (u, state)
    vector<vector<bool>> seen(n, vector<bool>(1 << n));

    for (int i = 0; i < n; ++i)
      q.emplace(i, 1 << i);

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [u, state] = q.front();
        q.pop();
        if (state == goal)
          return ans;
        if (seen[u][state])
          continue;
        seen[u][state] = true;
        for (const int v : graph[u])
          q.emplace(v, state | (1 << v));
      }
      ++ans;
    }

    return -1;
  }
};
