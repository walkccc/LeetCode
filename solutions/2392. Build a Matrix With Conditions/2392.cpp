class Solution {
 public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                  vector<vector<int>>& colConditions) {
    const vector<int> rowOrder = topologicalSort(rowConditions, k);
    if (rowOrder.empty())
      return {};

    const vector<int> colOrder = topologicalSort(colConditions, k);
    if (colOrder.empty())
      return {};

    vector<vector<int>> ans(k, vector<int>(k));
    vector<int> nodeToRowIndex(k + 1);

    for (int i = 0; i < k; ++i)
      nodeToRowIndex[rowOrder[i]] = i;

    for (int j = 0; j < k; ++j) {
      const int node = colOrder[j];
      const int i = nodeToRowIndex[node];
      ans[i][j] = node;
    }

    return ans;
  }

 private:
  vector<int> topologicalSort(const vector<vector<int>>& conditions, int n) {
    vector<int> order;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegrees(n + 1);
    queue<int> q;

    // Build the graph.
    for (const vector<int>& condition : conditions) {
      const int u = condition[0];
      const int v = condition[1];
      graph[u].push_back(v);
      ++inDegrees[v];
    }

    // Perform topological sorting.
    for (int i = 1; i <= n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      order.push_back(u);
      for (const int v : graph[u])
        if (--inDegrees[v] == 0)
          q.push(v);
    }

    return order.size() == n ? order : vector<int>();
  }
};
