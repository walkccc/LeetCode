class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> graph(n);
    using T = tuple<int, int, int>;  // (d, u, stops)
    priority_queue<T, vector<T>, greater<>> minHeap;
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

    minHeap.emplace(0, src, k + 1);  // start with node src with d == 0
    dist[src][k + 1] = 0;

    for (const auto& f : flights) {
      const int u = f[0];
      const int v = f[1];
      const int w = f[2];
      graph[u].emplace_back(v, w);
    }

    while (!minHeap.empty()) {
      const auto [d, u, stops] = minHeap.top();
      minHeap.pop();
      if (u == dst)
        return d;
      if (stops > 0)
        for (const auto& [v, w] : graph[u]) {
          const int newDist = d + w;
          if (newDist < dist[v][stops - 1]) {
            dist[v][stops - 1] = newDist;
            minHeap.emplace(newDist, v, stops - 1);
          }
        }
    }

    return -1;
  }
};
