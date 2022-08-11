class Solution {
 public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    int ans = 0;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
    queue<int> q;

    // build graph
    for (const auto& r : relations) {
      const int u = r[0] - 1;
      const int v = r[1] - 1;
      graph[u].push_back(v);
      ++inDegree[v];
    }

    // topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        --n;
        for (const int v : graph[u])
          if (--inDegree[v] == 0)
            q.push(v);
      }
      ++ans;
    }

    return n == 0 ? ans : -1;
  }
};
