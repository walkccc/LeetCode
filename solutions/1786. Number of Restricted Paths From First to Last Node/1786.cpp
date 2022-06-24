struct T {
  int u;
  int d;
  T(int u, int d) : u(u), d(d) {}
};

class Solution {
 public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    constexpr int kMod = 1e9 + 7;
    vector<vector<pair<int, int>>> graph(n + 1);
    auto compare = [](const T& a, const T& b) { return a.d > b.d; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    vector<int> dist(n + 1, INT_MAX);  // dist[i] := dist(node i, node n)
    vector<int> count(n + 1);  // count[i] := # of restricted path from i -> n

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      const int w = e[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    minHeap.emplace(n, 0);
    dist[n] = 0;
    count[n] = 1;

    while (!minHeap.empty()) {
      const auto [u, d] = minHeap.top();
      minHeap.pop();
      if (d > dist[u])
        continue;
      for (const auto& [v, w] : graph[u]) {
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(v, dist[v]);
        }
        if (dist[u] > dist[v]) {
          count[u] += count[v];
          count[u] %= kMod;
        }
      }
    }

    return count[1];
  }
};
