class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    const int n = colors.length();
    int ans = 0;
    int processed = 0;
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);
    queue<int> q;
    vector<vector<int>> count(n, vector<int>(26));

    // Build the graph.
    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int out = q.front();
      q.pop();
      ++processed;
      ans = max(ans, ++count[out][colors[out] - 'a']);
      for (const int in : graph[out]) {
        for (int i = 0; i < 26; ++i)
          count[in][i] = max(count[in][i], count[out][i]);
        if (--inDegrees[in] == 0)
          q.push(in);
      }
    }

    return processed == n ? ans : -1;
  }
};
