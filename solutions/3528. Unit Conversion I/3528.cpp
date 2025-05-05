class Solution {
 public:
  vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
    constexpr int kMod = 1'000'000'007;
    const int n = conversions.size() + 1;
    vector<int> ans(n);
    ans[0] = 1;
    queue<int> q{{0}};
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& conversion : conversions) {
      const int u = conversion[0];
      const int v = conversion[1];
      const int factor = conversion[2];
      graph[u].emplace_back(v, factor);
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const auto& [v, factor] : graph[u]) {
        ans[v] = (static_cast<long>(ans[u]) * factor) % kMod;
        q.push(v);
      }
    }

    return ans;
  }
};
