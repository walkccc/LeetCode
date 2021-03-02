struct T {
  int u;
  int dist;
};

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<bool> seen(N + 1);
    auto compare = [](const T& a, const T& b) { return a.dist > b.dist; };
    // {v, w}: min-heap sorted by w
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);
    pq.push({K, 0});  // start with node K with dist == 0

    for (const auto& time : times)
      graph[time[0]].push_back({time[1], time[2]});

    while (!pq.empty()) {
      const auto [u, dist] = pq.top();
      pq.pop();
      if (seen[u])
        continue;
      seen[u] = true;
      if (--N == 0)
        return dist;
      for (const auto& [v, w] : graph[u])
        pq.push({v, dist + w});
    }

    return -1;
  }
};
