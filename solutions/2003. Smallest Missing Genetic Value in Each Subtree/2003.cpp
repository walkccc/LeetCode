class Solution {
 public:
  vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                          vector<int>& nums) {
    const int n = parents.size();
    vector<int> ans(n, 1);
    vector<vector<int>> tree(n);
    unordered_set<int> seen;
    int minMiss = 1;

    for (int i = 1; i < n; ++i)
      tree[parents[i]].push_back(i);

    int nodeThatsOne = getNode(nums);
    if (nodeThatsOne == -1)
      return ans;

    int u = nodeThatsOne;
    int prev = -1;  // the u that just handled

    // Upward from `nodeThatsOne` to the root `u`.
    while (u != -1) {
      for (const int v : tree[u])
        if (v != prev)
          dfs(v, tree, seen, nums);
      seen.insert(nums[u]);
      while (seen.contains(minMiss))
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

  void dfs(int u, const vector<vector<int>>& tree, unordered_set<int>& seen,
           const vector<int>& nums) {
    seen.insert(nums[u]);
    for (const int v : tree[u])
      dfs(v, tree, seen, nums);
  }
};
