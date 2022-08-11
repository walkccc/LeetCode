enum class Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), Color::WHITE);

    for (int i = 0; i < graph.size(); ++i)
      if (colors[i] == Color::WHITE &&
          !isValidColor(graph, i, colors, Color::RED))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int u,
                    vector<Color>& colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[u] != Color::WHITE)
      return colors[u] == color;

    colors[u] = color;  // always paint w/ `color`

    // all children should have valid colors
    for (const int v : graph[u])
      if (!isValidColor(graph, v, colors,
                        color == Color::RED ? Color::GREEN : Color::RED))
        return false;

    return true;
  }
};
