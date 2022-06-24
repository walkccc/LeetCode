enum class Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), Color::WHITE);

    for (int i = 0; i < graph.size(); ++i) {
      // already colored, do nothing
      if (colors[i] != Color::WHITE)
        continue;
      // colors[i] == Color::WHITE
      colors[i] = Color::RED;  // always paint w/ Color::RED
      // BFS
      queue<int> q{{i}};
      while (!q.empty()) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          if (colors[v] == colors[u])
            return false;
          if (colors[v] == Color::WHITE) {
            colors[v] = colors[u] == Color::RED ? Color::GREEN : Color::RED;
            q.push(v);
          }
        }
      }
    }

    return true;
  }
};
