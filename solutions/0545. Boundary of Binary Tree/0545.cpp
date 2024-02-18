class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (root == nullptr)
      return {};
    vector<int> ans{root->val};
    dfs(root->left, true, false, ans);
    dfs(root->right, false, true, ans);
    return ans;
  }

 private:
  // 1. root->left is left boundary if root is left boundary.
  //    root->right if left boundary if root->left == nullptr.
  // 2. Same applys for right boundary.
  // 3. If root is left boundary, add it before 2 children - preorder.
  //    If root is right boundary, add it after 2 children - postorder.
  // 4. A leaf that is neighter left/right boundary belongs to the bottom.
  void dfs(TreeNode* root, bool lb, bool rb, vector<int>& ans) {
    if (root == nullptr)
      return;
    if (lb)
      ans.push_back(root->val);
    if (!lb && !rb && root->left == nullptr && root->right != nullptr)
      ans.push_back(root->val);

    dfs(root->left, lb, rb && root->right == nullptr, ans);
    dfs(root->right, lb && root->left == nullptr, rb, ans);
    if (rb)
      ans.push_back(root->val);
  }
};
