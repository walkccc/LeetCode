class Solution {
 public:
  long long maxScore(vector<vector<int>>& edges) {
    const int n = edges.size();
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < n; ++i) {
      const int parent = edges[i][0];
      const int weight = edges[i][1];
      if (parent != -1)
        graph[parent].emplace_back(i, weight);
    }

    const auto [takeRoot, notTakeRoot] = dfs(graph, 0);
    return max(takeRoot, notTakeRoot);
  }

 private:
  // Returns (the maximum sum at u if we take one u->v edge,
  //          the maximum sum at u if we don't take any child edge).
  pair<long long, long long> dfs(const vector<vector<pair<int, int>>>& graph,
                                 int u) {
    long long bestEdge = 0;
    long long notTakeU = 0;

    for (const auto& [v, w] : graph[u]) {
      const auto [takeV, notTakeV] = dfs(graph, v);
      bestEdge = max(bestEdge, w + notTakeV - takeV);
      notTakeU += takeV;
    }

    return {bestEdge + notTakeU, notTakeU};
  }
};
