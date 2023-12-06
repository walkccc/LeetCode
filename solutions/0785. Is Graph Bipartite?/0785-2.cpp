enum class Color { kWhite, kRed, kGreen };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), Color::kWhite);

    for (int i = 0; i < graph.size(); ++i)
      if (colors[i] == Color::kWhite &&
          !isValidColor(graph, i, colors, Color::kRed))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int u,
                    vector<Color>& colors, Color color) {
    // The painted color should be same as the `color`.
    if (colors[u] != Color::kWhite)
      return colors[u] == color;

    colors[u] = Color::kRed;

    // All the children should have valid colors.
    for (const int v : graph[u])
      if (!isValidColor(graph, v, colors,
                        color == Color::kRed ? Color::kGreen : Color::kRed))
        return false;

    return true;
  }
};
