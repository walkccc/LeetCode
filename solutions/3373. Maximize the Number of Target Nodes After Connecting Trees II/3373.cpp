class Solution {
 public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                             vector<vector<int>>& edges2) {
    const int n = edges1.size() + 1;
    const int m = edges2.size() + 1;
    vector<int> ans;
    const vector<vector<int>> graph1 = buildGraph(edges1);
    const vector<vector<int>> graph2 = buildGraph(edges2);
    vector<bool> parity1(n);
    vector<bool> parity2(m);  // placeholder (parity2 is not used)
    const int even1 = dfs(graph1, 0, -1, parity1, /*isEven=*/true);
    const int even2 = dfs(graph2, 0, -1, parity2, /*isEven=*/true);
    const int odd1 = n - even1;
    const int odd2 = m - even2;

    for (int i = 0; i < n; ++i) {
      const int tree1 = parity1[i] ? even1 : odd1;
      // Can connect the current node in tree1 to either an even node or an odd
      // node in tree2.
      const int tree2 = max(even2, odd2);
      ans.push_back(tree1 + tree2);
    }

    return ans;
  }

 private:
  // Returns the number of nodes that can be reached from u with even steps.
  int dfs(const vector<vector<int>>& graph, int u, int prev,
          vector<bool>& parity, bool isEven) {
    int res = isEven ? 1 : 0;
    parity[u] = isEven;
    for (const int v : graph[u])
      if (v != prev)
        res += dfs(graph, v, u, parity, !isEven);
    return res;
  }

  vector<vector<int>> buildGraph(const vector<vector<int>>& edges) {
    vector<vector<int>> graph(edges.size() + 1);
    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    return graph;
  }
};
