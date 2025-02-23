class Solution {
 public:
  vector<int> longestSpecialPath(vector<vector<int>>& edges,
                                 vector<int>& nums) {
    vector<vector<pair<int, int>>> graph(nums.size());

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    int maxLength = 0;
    int minNodes = 1;
    dfs(graph, 0, -1, 0, 1, /*prefix=*/{0}, /*lastSeenDepth=*/{}, nums,
        maxLength, minNodes);
    return {maxLength, minNodes};
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph, int u, int prev,
           int leftBoundary, int currentDepth, vector<int>&& prefix,
           unordered_map<int, int>&& lastSeenDepth, const vector<int>& nums,
           int& maxLength, int& minNodes) {
    const int prevDepth = lastSeenDepth[nums[u]];
    lastSeenDepth[nums[u]] = currentDepth;
    leftBoundary = max(leftBoundary, prevDepth);

    const int length = prefix.back() - prefix[leftBoundary];
    const int nodes = currentDepth - leftBoundary;
    if (length > maxLength || (length == maxLength && nodes < minNodes)) {
      maxLength = length;
      minNodes = nodes;
    }

    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      prefix.push_back(prefix.back() + w);
      dfs(graph, v, u, leftBoundary, currentDepth + 1, std::move(prefix),
          std::move(lastSeenDepth), nums, maxLength, minNodes);
      prefix.pop_back();
    }

    lastSeenDepth[nums[u]] = prevDepth;
  }
};
