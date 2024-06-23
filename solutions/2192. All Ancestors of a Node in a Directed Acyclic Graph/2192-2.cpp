class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    vector<set<int>> ancestors(n);  //  {u: {ancestors}}
    vector<int> inDegrees(n);
    queue<int> q;

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
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          ancestors[v].insert(u);
          std::copy(ancestors[u].begin(), ancestors[u].end(),
                    std::inserter(ancestors[v], ancestors[v].end()));
          if (--inDegrees[v] == 0)
            q.push(v);
        }
      }
    }

    for (const set<int>& nodes : ancestors)
      ans.push_back({nodes.begin(), nodes.end()});

    return ans;
  }
};
