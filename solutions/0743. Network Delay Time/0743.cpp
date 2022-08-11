class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    using P = pair<int, int>;
    vector<vector<P>> graph(n);
    priority_queue<P, vector<P>, greater<>> minHeap;  // (d, u)
    vector<bool> seen(n);

    for (const auto& t : times) {
      const int u = t[0] - 1;
      const int v = t[1] - 1;
      const int w = t[2];
      graph[u].emplace_back(v, w);
    }

    minHeap.emplace(0, k - 1);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (seen[u])
        continue;
      seen[u] = true;
      if (--n == 0)
        return d;
      for (const auto& [v, w] : graph[u])
        minHeap.emplace(d + w, v);
    }

    return -1;
  }
};
