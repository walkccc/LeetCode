struct T {
  int u;
  int dist;
  int k;
};

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    vector<vector<pair<int, int>>> graph(n);
    auto compare = [](const T& a, const T& b) { return a.dist > b.dist; };
    // {v, w}: min-heap sorted by w
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);
    pq.push({src, 0, K + 1});  // start with node src with dist == 0

    for (const auto& f : flights)
      graph[f[0]].push_back({f[1], f[2]});

    while (!pq.empty()) {
      const auto [u, dist, k] = pq.top();
      pq.pop();
      if (u == dst)
        return dist;
      if (k > 0)
        for (const auto& [v, w] : graph[u])
          pq.push({v, dist + w, k - 1});
    }

    return -1;
  }
};
