enum Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), WHITE);

    for (int i = 0; i < graph.size(); ++i)
      if (colors[i] == WHITE && !isValidColor(graph, i, colors, RED))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int u,
                    vector<Color>& colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[u] != WHITE)
      return colors[u] == color;

    colors[u] = color;  // always paint w/ `color`

    // all children should have valid colors
    for (const int v : graph[u])
      if (!isValidColor(graph, v, colors, color == RED ? GREEN : RED))
        return false;

    return true;
  }
};
