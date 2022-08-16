class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (!root)
      return {};
    vector<int> ans{root->val};
    dfs(root->left, true, false, ans);
    dfs(root->right, false, true, ans);
    return ans;
  }

 private:
  /**
   * 1. root->left is left boundary if root is left boundary
   *    root->right if left boundary if root->left == nullptr
   * 2. same applys for right boundary
   * 3. if root is left boundary, add it before 2 children - preorder
   *    if root is right boundary, add it after 2 children - postorder
   * 4. a leaf that is neighter left/right boundary belongs to the bottom
   */
  void dfs(TreeNode* root, bool lb, bool rb, vector<int>& ans) {
    if (!root)
      return;
    if (lb)
      ans.push_back(root->val);
    if (!lb && !rb && !root->left && !root->right)
      ans.push_back(root->val);

    dfs(root->left, lb, rb && !root->right, ans);
    dfs(root->right, lb && !root->left, rb, ans);
    if (rb)
      ans.push_back(root->val);
  }
};
