class Solution {
 public:
  vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // Randomly choose a node with the minimum degree as the corner.
    const int corner =
        ranges::min_element(graph, ranges::less{}, &vector<int>::size) -
        graph.begin();

    vector<bool> seen(n);
    seen[corner] = true;
    const vector<int> firstRow = getFirstRow(graph, corner, seen);
    const int cols = firstRow.size();
    const int rows = n / cols;

    vector<vector<int>> ans(rows, vector<int>(cols));
    ans[0] = firstRow;

    for (int i = 1; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
        for (const int v : graph[ans[i - 1][j]])
          if (!seen[v]) {
            ans[i][j] = v;
            seen[v] = true;
            break;
          }

    return ans;
  }

 private:
  vector<int> getFirstRow(vector<vector<int>>& graph, int corner,
                          vector<bool>& seen) {
    const int cornerDegree = graph[corner].size();
    vector<int> row = {corner};

    // Continue appending neighbors until we hit another corner.
    while (row.size() == 1 || graph[row.back()].size() == cornerDegree + 1) {
      // Sort neighbors by degree to prioritize smaller ones (shortest row built
      // first).
      vector<int>& neighbors = graph[row.back()];
      ranges::sort(neighbors, ranges::less{},
                   [&graph](int v) { return graph[v].size(); });
      for (const int v : neighbors)
        if (!seen[v] && (graph[v].size() == cornerDegree ||
                         graph[v].size() == cornerDegree + 1)) {
          row.push_back(v);
          seen[v] = true;
          break;
        }
    }

    return row;
  }
};
