class Solution {
 public:
  int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
    const int n = nums.size();
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> tree(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    for (int i = n; i > 1; --i)
      // Split the tree into i parts, i.e. delete (i - 1) edges.
      if (sum % i == 0 && dfs(nums, tree, 0, sum / i, vector<bool>(n)) == 0)
        return i - 1;

    return 0;
  }

 private:
  static constexpr int kMax = 1'000'000'000;

  // Returns the sum of the subtree rooted at u substracting the sum of the
  // deleted subtrees.
  int dfs(const vector<int>& nums, const vector<vector<int>>& tree, int u,
          int target, vector<bool>&& seen) {
    int sum = nums[u];
    seen[u] = true;

    for (const int v : tree[u]) {
      if (seen[v])
        continue;
      sum += dfs(nums, tree, v, target, move(seen));
      if (sum > target)
        return kMax;
    }

    // Delete the tree that has sum == target.
    if (sum == target)
      return 0;
    return sum;
  }
};
