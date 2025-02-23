class Solution {
 public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    vector<int> ans(nums.size(), -1);
    vector<vector<int>> tree(nums.size());
    // stacks[i] := (node, depth)s of nodes with value i
    vector<stack<pair<int, int>>> stacks(kMax + 1);

    for (const vector<int> edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, /*prev=*/-1, /*depth=*/0, nums, stacks, ans);
    return ans;
  }

 private:
  static constexpr int kMax = 50;

  void dfs(const vector<vector<int>>& tree, int u, int prev, int depth,
           const vector<int>& nums, vector<stack<pair<int, int>>>& stacks,
           vector<int>& ans) {
    ans[u] = getAncestor(u, stacks, nums);
    stacks[nums[u]].push({u, depth});

    for (const int v : tree[u])
      if (v != prev)
        dfs(tree, v, u, depth + 1, nums, stacks, ans);

    stacks[nums[u]].pop();
  }

  int getAncestor(int u, const vector<stack<pair<int, int>>>& stacks,
                  const vector<int>& nums) {
    int maxNode = -1;
    int maxDepth = -1;
    for (int i = 1; i <= kMax; ++i)
      if (!stacks[i].empty() && stacks[i].top().second > maxDepth &&
          __gcd(nums[u], i) == 1) {
        maxNode = stacks[i].top().first;
        maxDepth = stacks[i].top().second;
      }
    return maxNode;
  }
};
