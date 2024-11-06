class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> ans(n);
    vector<int> count(n, 1);
    vector<unordered_set<int>> tree(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].insert(v);
      tree[v].insert(u);
    }

    postorder(tree, 0, /*prev=*/-1, count, ans);
    preorder(tree, 0, /*prev=*/-1, count, ans);
    return ans;
  }

 private:
  void postorder(const vector<unordered_set<int>>& tree, int u, int prev,
                 vector<int>& count, vector<int>& ans) {
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      postorder(tree, v, u, count, ans);
      count[u] += count[v];
      ans[u] += ans[v] + count[v];
    }
  }

  void preorder(const vector<unordered_set<int>>& tree, int u, int prev,
                vector<int>& count, vector<int>& ans) {
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      // count[v] us are 1 step closer from v than prev.
      // (n - count[v]) us are 1 step farther from v than prev.
      ans[v] = ans[u] - count[v] + (tree.size() - count[v]);
      preorder(tree, v, u, count, ans);
    }
  }
};
