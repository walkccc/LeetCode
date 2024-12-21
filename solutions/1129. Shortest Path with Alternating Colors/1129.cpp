enum class Color { kInit, kRed, kBlue };

class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<int> ans(n, -1);
    vector<vector<pair<int, Color>>> graph(n);  // graph[u] := [(v, edgeColor)]
    queue<pair<int, Color>> q{{{0, Color::kInit}}};  // [(u, prevColor)]

    for (const vector<int>& edge : redEdges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, Color::kRed);
    }

    for (const vector<int>& edge : blueEdges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, Color::kBlue);
    }

    for (int step = 0; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [u, prevColor] = q.front();
        q.pop();
        ans[u] = ans[u] == -1 ? step : ans[u];
        for (auto& [v, edgeColor] : graph[u]) {
          if (v == -1 || edgeColor == prevColor)
            continue;
          q.emplace(v, edgeColor);
          v = -1;  // Mark (u, v) as used.
        }
      }

    return ans;
  }
};
