class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size());  // 1: red, -1: green

    function<bool(int, int)> isValidColor = [&](int node, int color) {
      if (colors[node] != 0)  // the painted color should be same as the `color`
        return colors[node] == color;

      colors[node] = color;  // paint the node with `color`

      for (const int neighbor : graph[node])  // all neighbors should have valid colors
        if (!isValidColor(neighbor, -color))
          return false;

      return true;
    };

    for (int i = 0; i < graph.size(); ++i)
      if (colors[i] == 0 && !isValidColor(i, 1))  // start to paint it with `1`
        return false;

    return true;
  }
};