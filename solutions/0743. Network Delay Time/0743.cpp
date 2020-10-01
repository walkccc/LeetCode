class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    int ans = 0;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> seen(N + 1);
    priority_queue<pair<int, int>> pq;  // {w, v}: min-heap sorted by w
    pq.push({-0, K});

    for (const vector<int>& time : times)
      graph[time[0]].push_back({time[1], time[2]});

    while (!pq.empty()) {
      const auto [dist, u] = pq.top(); pq.pop();
      if (seen[u]) continue;
      seen[u] = true;
      ans = -dist;  // the minDist to go to current node u
      if (--N == 0) return ans;
      for (const auto& [v, w] : graph[u])
        pq.push({dist - w, v});
    }

    return -1;
  }
};