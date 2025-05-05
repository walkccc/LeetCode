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
    dfs(graph, 0, -1, /*leftBoundary=*/{0, 0}, /*prefix=*/{0},
        /*lastSeenDepth=*/{}, nums, maxLength, minNodes);
    return {maxLength, minNodes};
  }

 private:
  void dfs(const vector<vector<pair<int, int>>>& graph, int u, int prev,
           vector<int> leftBoundary, vector<int>&& prefix,
           unordered_map<int, int>&& lastSeenDepth, const vector<int>& nums,
           int& maxLength, int& minNodes) {
    const int prevDepth = lastSeenDepth[nums[u]];
    lastSeenDepth[nums[u]] = prefix.size();

    if (prevDepth != 0) {
      leftBoundary.push_back(prevDepth);
      ranges::sort(leftBoundary);
      leftBoundary = {leftBoundary[leftBoundary.size() - 2],
                      leftBoundary.back()};
    }

    const int length = prefix.back() - prefix[leftBoundary[0]];
    const int nodes = prefix.size() - leftBoundary[0];
    if (length > maxLength || (length == maxLength && nodes < minNodes)) {
      maxLength = length;
      minNodes = nodes;
    }

    for (const auto& [v, w] : graph[u]) {
      if (v == prev)
        continue;
      prefix.push_back(prefix.back() + w);
      dfs(graph, v, u, leftBoundary, std::move(prefix),
          std::move(lastSeenDepth), nums, maxLength, minNodes);
      prefix.pop_back();
    }

    lastSeenDepth[nums[u]] = prevDepth;
  }
};
