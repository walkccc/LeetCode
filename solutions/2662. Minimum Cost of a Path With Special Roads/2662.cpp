class Solution {
 public:
  int minimumCost(vector<int>& start, vector<int>& target,
                  vector<vector<int>>& specialRoads) {
    return dijkstra(specialRoads, start[0], start[1], target[0], target[1]);
  }

 private:
  int dijkstra(const vector<vector<int>>& specialRoads, int srcX, int srcY,
               int dstX, int dstY) {
    const int n = specialRoads.size();
    // dist[i] := the minimum distance of (srcX, srcY) to
    // specialRoads[i](x2, y2)
    vector<int> dist(specialRoads.size(), INT_MAX);
    using P = pair<int, int>;  // (d, u), where u := the i-th specialRoads
    priority_queue<P, vector<P>, greater<>> minHeap;

    // (srcX, srcY) -> (x1, y1) to cost -> (x2, y2)
    for (int u = 0; u < n; ++u) {
      const int x1 = specialRoads[u][0];
      const int y1 = specialRoads[u][1];
      const int cost = specialRoads[u][4];
      const int d = abs(x1 - srcX) + abs(y1 - srcY) + cost;
      dist[u] = d;
      minHeap.emplace(dist[u], u);
    }

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      const int ux2 = specialRoads[u][2];
      const int uy2 = specialRoads[u][3];
      for (int v = 0; v < n; ++v) {
        if (v == u)
          continue;
        const int vx1 = specialRoads[v][0];
        const int vy1 = specialRoads[v][1];
        const int vcost = specialRoads[v][4];
        // (ux2, uy2) -> (vx1, vy1) to vcost -> (vx2, vy2)
        const int newDist = d + abs(vx1 - ux2) + abs(vy1 - uy2) + vcost;
        if (newDist < dist[v]) {
          dist[v] = newDist;
          minHeap.emplace(dist[v], v);
        }
      }
    }

    int ans = abs(dstX - srcX) + abs(dstY - srcY);
    for (int u = 0; u < n; ++u) {
      const int x2 = specialRoads[u][2];
      const int y2 = specialRoads[u][3];
      // (srcX, srcY) -> (x2, y2) -> (dstX, dstY).
      ans = min(ans, dist[u] + abs(dstX - x2) + abs(dstY - y2));
    }
    return ans;
  }
};
