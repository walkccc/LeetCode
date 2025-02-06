class Solution {
 public:
  int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
    int ans = -1;
    vector<set<pair<int, int>>> graph(scores.size());  // {(score, node)}

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace(scores[v], v);
      graph[v].emplace(scores[u], u);
      if (graph[u].size() > 3)
        graph[u].erase(graph[u].begin());
      if (graph[v].size() > 3)
        graph[v].erase(graph[v].begin());
    }

    // To find the target sequence: a - u - v - b, enumerate each edge (u, v),
    // and find a (u's child) and b (v's child). That's why we find the 3
    // children that have the highest scores because one of the 3 children is
    // guaranteed to be valid.
    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      for (const auto& [scoreA, a] : graph[u])
        for (const auto& [scoreB, b] : graph[v])
          if (a != b && a != v && b != u)
            ans = max(ans, scoreA + scores[u] + scores[v] + scoreB);
    }

    return ans;
  }
};
