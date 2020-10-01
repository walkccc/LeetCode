class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    const int n = graph.size();
    const int goal = (1 << n) - 1;

    int ans = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(1 << n));

    for (int i = 0; i < graph.size(); ++i) q.push({i, 1 << i});

    while (!q.empty()) {
      int s = q.size();
      while (s--) {
        auto p = q.front();
        q.pop();
        int node = p.first;
        int state = p.second;
        if (state == goal) return ans;
        if (visited[node][state]) continue;
        visited[node][state] = 1;
        for (int next : graph[node]) q.push({next, state | (1 << next)});
      }
      ++ans;
    }

    return -1;
  }
};