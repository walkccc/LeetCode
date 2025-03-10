class Solution {
 public:
  int minCameraCover(TreeNode* root) {
    vector<int> ans = dfs(root);
    return min(ans[1], ans[2]);
  }

 private:
  // 0 := all the nodes below the root are covered except the root
  // 1 := all the nodes below and including the root are covered with no camera
  // 2 := all nodes below and including the root are covered with a camera
  vector<int> dfs(TreeNode* root) {
    if (root == nullptr)
      return {0, 0, 1000};

    vector<int> l = dfs(root->left);
    vector<int> r = dfs(root->right);

    const int s0 = l[1] + r[1];
    const int s1 = min(l[2] + min(r[1], r[2]),  //
                       r[2] + min(l[1], l[2]));
    const int s2 = min({l[0], l[1], l[2]}) +  //
                   min({r[0], r[1], r[2]}) + 1;
    return {s0, s1, s2};
  }
};
