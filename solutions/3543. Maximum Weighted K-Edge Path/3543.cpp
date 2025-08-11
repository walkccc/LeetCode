class Solution {
 public:
  int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
    vector<vector<pair<int, int>>> graph(n);
    // dp[u][i] := the set of possible path sums ending at node u with i edges
    vector<unordered_map<int, unordered_set<int>>> dp(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
    }

    for (int u = 0; u < n; ++u)
      dp[u][0].insert(0);  // zero edges = sum 0

    for (int i = 0; i < k; ++i)
      for (int u = 0; u < n; ++u)
        if (dp[u].contains(i))
          for (const int currSum : dp[u][i])
            for (const auto& [v, w] : graph[u]) {
              const int newSum = currSum + w;
              if (newSum < t)
                dp[v][i + 1].insert(newSum);
            }

    int ans = -1;

    for (int u = 0; u < n; ++u)
      if (dp[u].contains(k))
        for (const int sum : dp[u][k])
          ans = max(ans, sum);

    return ans;
  }
};
