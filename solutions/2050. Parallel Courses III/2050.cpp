class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
    queue<int> q;
    vector<int> dist(time);

    // Build graph.
    for (const vector<int>& r : relations) {
      const int u = r[0] - 1;
      const int v = r[1] - 1;
      graph[u].push_back(v);
      ++inDegree[v];
    }

    // Topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        dist[v] = max(dist[v], dist[u] + time[v]);
        if (--inDegree[v] == 0)
          q.push(v);
      }
    }

    return ranges::max(dist);
  }
};
