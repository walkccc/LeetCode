class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = graph.size();
    const int goal = (1 << n) - 1;

    int ans = 0;
    queue<pair<int, int>> q;  // {node, state (i-th bit)}
    vector<vector<bool>> seen(n, vector<bool>(1 << n));

    for (int i = 0; i < n; ++i)
      q.push({i, 1 << i});

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        const auto [node, state] = q.front();
        q.pop();
        if (state == goal)
          return ans;
        if (seen[node][state])
          continue;
        seen[node][state] = true;
        for (const int child : graph[node])
          q.push({child, state | (1 << child)});
      }
      ++ans;
    }

    return -1;
  }
};
