class Solution {
 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ans;

    depth(root, ans);
    return ans;
  }

 private:
  // Returns the depth of the root (0-indexed).
  int depth(TreeNode* root, vector<vector<int>>& ans) {
    if (root == nullptr)
      return -1;

    const int l = depth(root->left, ans);
    const int r = depth(root->right, ans);
    const int h = 1 + max(l, r);
    if (ans.size() == h)  // Meet a leaf.
      ans.push_back({});

    ans[h].push_back(root->val);
    return h;
  }
};
