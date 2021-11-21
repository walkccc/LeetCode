class Solution {
 public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<int> ans(N);
    vector<int> count(N, 1);
    vector<unordered_set<int>> tree(N);

    for (const auto& edge : edges) {
      tree[edge[0]].insert(edge[1]);
      tree[edge[1]].insert(edge[0]);
    }

    postorder(tree, 0, -1, count, ans);
    preorder(tree, 0, -1, count, ans);

    return ans;
  }

 private:
  void postorder(const vector<unordered_set<int>>& tree, int node, int parent,
                 vector<int>& count, vector<int>& ans) {
    for (const int child : tree[node]) {
      if (child == parent)
        continue;
      postorder(tree, child, node, count, ans);
      count[node] += count[child];
      ans[node] += ans[child] + count[child];
    }
  }

  void preorder(const vector<unordered_set<int>>& tree, int node, int parent,
                vector<int>& count, vector<int>& ans) {
    for (const int child : tree[node]) {
      if (child == parent)
        continue;
      // count[child] nodes are 1 step closer from child than parent
      // (N - count[child]) nodes are 1 step farther from child than parent
      ans[child] = ans[node] - count[child] + (tree.size() - count[child]);
      preorder(tree, child, node, count, ans);
    }
  }
};
