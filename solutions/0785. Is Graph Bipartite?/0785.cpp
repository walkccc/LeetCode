enum class Color { kWhite, kRed, kGreen };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), Color::kWhite);

    for (int i = 0; i < graph.size(); ++i) {
      // Already colored, do nothing
      if (colors[i] != Color::kWhite)
        continue;
      // colors[i] == Color::kWhite
      colors[i] = Color::kRed;  // Always paint w/ Color::kRed
      // BFS
      queue<int> q{{i}};
      while (!q.empty()) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          if (colors[v] == colors[u])
            return false;
          if (colors[v] == Color::kWhite) {
            colors[v] = colors[u] == Color::kRed ? Color::kGreen : Color::kRed;
            q.push(v);
          }
        }
      }
    }

    return true;
  }
};
