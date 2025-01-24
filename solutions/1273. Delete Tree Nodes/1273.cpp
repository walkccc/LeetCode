struct T {
  int sum;
  int count;
};

class Solution {
 public:
  int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    vector<vector<int>> tree(nodes);

    for (int i = 1; i < parent.size(); ++i)
      tree[parent[i]].push_back(i);

    return dfs(tree, 0, value).count;
  }

 private:
  T dfs(const vector<vector<int>>& tree, int u, const vector<int>& value) {
    int sum = value[u];  // the root value
    int count = 1;       // this root

    for (const int v : tree[u]) {
      const T t = dfs(tree, v, value);
      sum += t.sum;
      count += t.count;
    }

    if (sum == 0)     // Delete this root.
      return {0, 0};  // So, its count = 0.
    return {sum, count};
  }
};
