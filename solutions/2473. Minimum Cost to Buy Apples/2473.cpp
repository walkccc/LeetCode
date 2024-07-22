class Solution {
 public:
  vector<long long> minCost(int n, vector<vector<int>>& roads,
                            vector<int>& appleCost, int k) {
    vector<long long> ans;
    vector<vector<pair<int, long>>> graph(n);

    for (const vector<int>& road : roads) {
      const int u = road[0] - 1;
      const int v = road[1] - 1;
      const int w = road[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i)
      ans.push_back(dijkstra(graph, i, appleCost, k));

    return ans;
  }

 private:
  long dijkstra(const vector<vector<pair<int, long>>>& graph, int i,
                const vector<int>& appleCost, int k) {
    vector<long> forwardCost(graph.size(), LONG_MAX);
    vector<long> totalCost(graph.size(), LONG_MAX);
    forwardCost[i] = 0;
    queue<int> q{{i}};

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const auto& [v, w] : graph[u]) {
        const long nextCost = forwardCost[u] + w;
        if (nextCost >= forwardCost[v])
          continue;
        forwardCost[v] = nextCost;
        // Take apple at city v and return back to city i.
        totalCost[v] = (k + 1) * nextCost + appleCost[v];
        q.push(v);
      }
    }

    return min(static_cast<long>(appleCost[i]), ranges::min(totalCost));
  }
};
