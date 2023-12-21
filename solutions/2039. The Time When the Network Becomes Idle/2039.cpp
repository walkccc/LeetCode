class Solution {
 public:
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    const int n = patience.size();
    int ans = 0;
    vector<vector<int>> graph(n);
    queue<int> q{{0}};
    vector<int> dist(n, INT_MAX);  // dist[i] := the distance between i and 0
    dist[0] = 0;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u])
          if (dist[v] == INT_MAX) {
            dist[v] = dist[u] + 1;
            q.push(v);
          }
      }
    }

    for (int i = 1; i < n; ++i) {
      const int numResending = (dist[i] * 2 - 1) / patience[i];
      const int lastResendingTime = patience[i] * numResending;
      const int lastArrivingTime = lastResendingTime + dist[i] * 2;
      ans = max(ans, lastArrivingTime);
    }

    return ans + 1;
  }
};
