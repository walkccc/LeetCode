class Solution {
 public:
  int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    const int n = vals.size();
    int ans = INT_MIN;
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, vals[v]);
      graph[v].emplace_back(u, vals[u]);
    }

    for (int i = 0; i < n; ++i) {
      priority_queue<int> maxHeap;
      for (const auto& [_, val] : graph[i])
        if (val > 0)
          maxHeap.push(val);
      int starSum = vals[i];
      for (int j = 0; j < k && !maxHeap.empty(); ++j)
        starSum += maxHeap.top(), maxHeap.pop();
      ans = max(ans, starSum);
    }

    return ans;
  }
};
