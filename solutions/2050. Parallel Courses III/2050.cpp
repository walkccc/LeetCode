class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);
    queue<int> q;
    vector<int> dist(time);

    // Build the graph.
    for (const vector<int>& r : relations) {
      const int u = r[0] - 1;
      const int v = r[1] - 1;
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        dist[v] = max(dist[v], dist[u] + time[v]);
        if (--inDegrees[v] == 0)
          q.push(v);
      }
    }

    return ranges::max(dist);
  }
};
