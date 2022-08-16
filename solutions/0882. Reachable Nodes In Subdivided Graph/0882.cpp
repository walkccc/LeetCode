class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    using P = pair<int, int>;
    vector<vector<P>> graph(n);
    priority_queue<P, vector<P>, greater<>> minHeap;  // (d, u)
    vector<int> dist(n, maxMoves + 1);

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      const int cnt = e[2];
      graph[u].emplace_back(v, cnt);
      graph[v].emplace_back(u, cnt);
    }

    minHeap.emplace(0, 0);
    dist[0] = 0;

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      // already takes maxMoves to reach u, can't explore anymore
      if (dist[u] >= maxMoves)
        break;
      for (const auto& [v, w] : graph[u]) {
        const int newDist = d + w + 1;
        if (newDist < dist[v]) {
          dist[v] = newDist;
          minHeap.emplace(newDist, v);
        }
      }
    }

    const int reachableNodes =
        count_if(begin(dist), end(dist), [&](int d) { return d <= maxMoves; });
    int reachableSubnodes = 0;

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      const int cnt = e[2];
      // reachable nodes of e from u
      const int a = dist[u] > maxMoves ? 0 : min(maxMoves - dist[u], cnt);
      // reachable nodes of e from v
      const int b = dist[v] > maxMoves ? 0 : min(maxMoves - dist[v], cnt);
      reachableSubnodes += min(a + b, cnt);
    }

    return reachableNodes + reachableSubnodes;
  }
};
