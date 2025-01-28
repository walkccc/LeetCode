class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<vector<int>> graph(n);
    vector<int> inDegrees(n);
    queue<int> q;

    // Build the graph.
    for (const vector<int>& relation : relations) {
      const int u = relation[0] - 1;
      const int v = relation[1] - 1;
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    int step = 0;
    for (; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        --n;
        for (const int v : graph[u])
          if (--inDegrees[v] == 0)
            q.push(v);
      }

    return n == 0 ? step : -1;
  }
};
