class Solution {
 public:
  long long maximumScoreAfterOperations(vector<vector<int>>& edges,
                                        vector<int>& values) {
    vector<vector<int>> tree(values.size());

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    return accumulate(values.begin(), values.end(), 0L) -
           dfs(tree, 0, /*prev=*/-1, values);
  }

 private:
  // Returns the minimum of sum to be reduced.
  long dfs(const vector<vector<int>>& tree, int u, int prev,
           const vector<int>& values) {
    if (u > 0 && tree[u].size() == 1)
      return values[u];
    long childrenSum = 0;
    for (const int v : tree[u])
      if (v != prev)
        childrenSum += dfs(tree, v, u, values);
    return min(childrenSum, static_cast<long>(values[u]));
  }
};
