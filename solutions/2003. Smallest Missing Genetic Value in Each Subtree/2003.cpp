class Solution {
 public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                          vector<int>& nums) {
    const int n = parents.size();
    vector<int> ans(n, 1);
    vector<vector<int>> graph(n);
    unordered_set<int> seen;
    int minMiss = 1;

    for (int i = 1; i < n; ++i)
      graph[parents[i]].push_back(i);

    int nodeThatsOne = getNode(nums);
    if (nodeThatsOne == -1)
      return ans;

    int u = nodeThatsOne;
    int prev = -1;  // the u that just handled

    // upward from nodeThatsOne to root u
    while (u != -1) {
      for (const int v : graph[u]) {
        if (v == prev)
          continue;
        dfs(v, graph, seen, nums);
      }
      seen.insert(nums[u]);
      while (seen.count(minMiss))
        ++minMiss;
      ans[u] = minMiss;
      prev = u;
      u = parents[u];
    }

    return ans;
  }

 private:
  int getNode(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 1)
        return i;
    return -1;
  }

  void dfs(int u, const vector<vector<int>>& graph, unordered_set<int>& seen,
           const vector<int>& nums) {
    seen.insert(nums[u]);
    for (const int v : graph[u])
      dfs(v, graph, seen, nums);
  }
};
