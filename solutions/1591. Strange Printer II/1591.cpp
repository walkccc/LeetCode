enum class State { kInit, kVisiting, kVisited };

class Solution {
 public:
  bool isPrintable(vector<vector<int>>& targetGrid) {
    constexpr int kMaxColor = 60;
    const int m = targetGrid.size();
    const int n = targetGrid[0].size();
    // graph[u] := {v1, v2} means v1 and v2 cover u
    vector<unordered_set<int>> graph(kMaxColor + 1);

    for (int color = 1; color <= kMaxColor; ++color) {
      // Get the rectangle of the current color.
      int minI = m;
      int minJ = n;
      int maxI = -1;
      int maxJ = -1;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (targetGrid[i][j] == color) {
            minI = min(minI, i);
            minJ = min(minJ, j);
            maxI = max(maxI, i);
            maxJ = max(maxJ, j);
          }
      // Add any color covering the current as the children.
      for (int i = minI; i <= maxI; ++i)
        for (int j = minJ; j <= maxJ; ++j)
          if (targetGrid[i][j] != color)
            graph[color].insert(targetGrid[i][j]);
    }

    vector<State> states(kMaxColor + 1);

    for (int color = 1; color <= kMaxColor; ++color)
      if (hasCycle(graph, color, states))
        return false;

    return true;
  }

 private:
  bool hasCycle(const vector<unordered_set<int>>& graph, int u,
                vector<State>& states) {
    if (states[u] == State::kVisiting)
      return true;
    if (states[u] == State::kVisited)
      return false;

    states[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, states))
        return true;
    states[u] = State::kVisited;

    return false;
  }
};
