class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    vector<set<int>> A(n);  //  {u: {ancestors}}
    vector<int> inDegree(n);
    queue<int> q;

    // build graph
    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
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
        for (const int v : graph[u]) {
          A[v].insert(u);
          std::copy(begin(A[u]), end(A[u]), std::inserter(A[v], end(A[v])));
          if (--inDegree[v] == 0)
            q.push(v);
        }
      }
    }

    for (auto& nodes : A)
      ans.push_back({begin(nodes), end(nodes)});

    return ans;
  }
};
