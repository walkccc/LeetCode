enum Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N + 1);
    vector<Color> colors(N + 1, WHITE);

    for (const auto& edge : dislikes) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    for (int i = 1; i <= N; ++i)
      if (colors[i] == WHITE && !isValidColor(graph, i, colors, RED))
        return false;

    return true;
  }

 private:
  bool isValidColor(const vector<vector<int>>& graph, int node,
                    vector<Color>& colors, Color color) {
    // the painted color should be same as the `color`
    if (colors[node] != WHITE)
      return colors[node] == color;

    colors[node] = color;  // always paint w/ `color`

    // all children should have valid colors
    for (const int child : graph[node])
      if (!isValidColor(graph, child, colors, color == RED ? GREEN : RED))
        return false;

    return true;
  }
};
