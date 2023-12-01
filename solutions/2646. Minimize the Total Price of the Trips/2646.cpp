class Solution {
 public:
  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price,
                        vector<vector<int>>& trips) {
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // count[i] := the number of times node i is traversed
    vector<int> count(n);

    for (const vector<int>& trip : trips) {
      const int start = trip[0];
      const int end = trip[1];
      vector<int> path;
      dfsCount(graph, start, /*prev=*/-1, end, count, path);
    }

    // dp[i][j] := the minimum price sum for the i-th node , where its parent is
    // halved parent or not halved not
    dp.resize(n, vector<int>(2, -1));
    return dfs(graph, 0, -1, price, count, false);
  }

 private:
  vector<vector<int>> dp;

  void dfsCount(const vector<vector<int>>& graph, int u, int prev, int end,
                vector<int>& count, vector<int>& path) {
    path.push_back(u);
    if (u == end) {
      for (const int i : path)
        ++count[i];
      return;
    }
    for (const int v : graph[u])
      if (v != prev)
        dfsCount(graph, v, u, end, count, path);
    path.pop_back();
  }

  int dfs(const vector<vector<int>>& graph, int u, int prev,
          const vector<int>& price, const vector<int>& count,
          int parentHalved) {
    if (dp[u][parentHalved] != -1)
      return dp[u][parentHalved];

    int sumWithFullNode = price[u] * count[u];
    for (const int v : graph[u])
      if (v != prev)
        sumWithFullNode += dfs(graph, v, u, price, count, false);

    if (parentHalved)  // Can't halve this node if its parent was halved.
      return dp[u][parentHalved] = sumWithFullNode;

    int sumWithHalvedNode = (price[u] / 2) * count[u];
    for (const int v : graph[u])
      if (v != prev)
        sumWithHalvedNode += dfs(graph, v, u, price, count, true);

    return dp[u][parentHalved] = min(sumWithFullNode, sumWithHalvedNode);
  }
};
