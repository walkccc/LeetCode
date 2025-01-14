class Solution {
 public:
  long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
    const int n = edges.size() + 1;
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dfs(graph, 0, -1, k).second;
  }

  // Returns
  // (the weight sum of the subtree rooted at u with at most k - 1 children,
  //  the weight sum of the subtree rooted at u with at most k children).
  pair<long, long> dfs(const vector<vector<pair<int, int>>>& graph, int u,
                       int prev, int k) {
    long weightSum = 0;
    priority_queue<long> diffs;

    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      const auto [subK1, subK] = dfs(graph, v, u, k);
      weightSum += subK;
      // If picking (u, v) makes the sum larger, we should pick it.
      diffs.push(max(0L, subK1 - subK + w));
    }

    long topK1 = 0;
    long topK = 0;

    for (int i = 0; i < k && !diffs.empty(); ++i) {
      if (i < k - 1)
        topK1 += diffs.top();
      topK += diffs.top();
      diffs.pop();
    }

    return {weightSum + topK1, weightSum + topK};
  };
};
