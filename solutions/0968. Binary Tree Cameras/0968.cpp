class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    vector<int> ans = dfs(root);
    return min(ans[1], ans[2]);
  }

 private:
  // 0 := all nodes below root are covered except root
  // 1 := all nodes below and including root are covered w/o camera here
  // 2 := all nodes below and including root are covered w/ camera here
  vector<int> dfs(TreeNode* root) {
    if (!root)
      return {0, 0, 1000};

    vector<int> l = dfs(root->left);
    vector<int> r = dfs(root->right);

    const int s0 = l[1] + r[1];
    const int s1 = min(l[2] + min(r[1], r[2]),
                       r[2] + min(l[1], l[2]));
    const int s2 = 1 + min({l[0], l[1], l[2]}) +
                       min({r[0], r[1], r[2]});

    return {s0, s1, s2};
  }
};
