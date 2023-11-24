class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    vector<set<int>> A(n);  //  {u: {ancestors}}
    vector<int> inDegrees(n);
    queue<int> q;

    // Build graph.
    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Topology
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          A[v].insert(u);
          std::copy(A[u].begin(), A[u].end(), std::inserter(A[v], A[v].end()));
          if (--inDegrees[v] == 0)
            q.push(v);
        }
      }
    }

    for (auto& nodes : A)
      ans.push_back({nodes.begin(), nodes.end()});

    return ans;
  }
};
