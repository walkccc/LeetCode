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
    // {v, w}: min-heap sorted by w
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);
    pq.emplace(n, 0);
    vector<int> dist(n + 1, INT_MAX);  // dist[i] := dist(node i, node n)
    vector<int> count(n + 1);  // count[i] := # of restricted path from i -> n
    dist[n] = 0;
    count[n] = 1;

    for (const auto& edge : edges) {
      graph[edge[0]].emplace_back(edge[1], edge[2]);
      graph[edge[1]].emplace_back(edge[0], edge[2]);
    }

    while (!pq.empty()) {
      const auto [u, d] = pq.top();
      pq.pop();
      if (d > dist[u])
        continue;
      for (const auto& [v, w] : graph[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.emplace(v, dist[v]);
        }
        if (dist[u] > dist[v])
          count[u] = (count[u] + count[v]) % kMod;
      }
    }

    return count[1];
  }
};
