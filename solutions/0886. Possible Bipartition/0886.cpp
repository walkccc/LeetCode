enum Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n + 1);
    vector<Color> colors(n + 1, Color::WHITE);

    for (const auto& d : dislikes) {
      const int u = d[0];
      const int v = d[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // reduce to 785. Is Graph Bipartite?
    for (int i = 1; i <= n; ++i)
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
