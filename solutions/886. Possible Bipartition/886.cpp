enum Color { kWhite, kRed, kGreen };

class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n + 1);
    vector<Color> colors(n + 1, Color::kWhite);

    for (const vector<int>& d : dislikes) {
      const int u = d[0];
      const int v = d[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // Reduce to 785. Is Graph Bipartite?
    for (int i = 1; i <= n; ++i)
      if (colors[i] == Color::kWhite &&
          !isValidColor(graph, i, colors, Color::kRed))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int u,
                    vector<Color>& colors, Color color) {
    // Always paint red for a white node.
    if (colors[u] != Color::kWhite)
      return colors[u] == color;

    colors[u] = color;  // Always paint the node with `color`.

    // All the children should have valid colors.
    for (const int v : graph[u])
      if (!isValidColor(graph, v, colors,
                        color == Color::kRed ? Color::kGreen : Color::kRed))
        return false;

    return true;
  }
};
