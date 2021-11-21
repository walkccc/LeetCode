enum Color { WHITE, RED, GREEN };

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<Color> colors(graph.size(), WHITE);

    for (int i = 0; i < graph.size(); ++i) {
      // if it's colored already, then we do nothing
      if (colors[i] != WHITE)
        continue;
      // colors[i] is Color.WHITE
      colors[i] = RED;  // always paint w/ RED
      // start doing BFS
      queue<int> q{{i}};
      while (!q.empty()) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          if (colors[v] == colors[u])
            return false;
          if (colors[v] == WHITE) {
            colors[v] = colors[u] == RED ? GREEN : RED;
            q.push(v);
          }
        }
      }
    }

    return true;
  }
};
