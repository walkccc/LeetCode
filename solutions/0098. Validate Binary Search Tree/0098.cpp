class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return dfs(root, nullptr, nullptr);
  }

 private:
  bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if (minNode && minNode->val >= root->val ||
        maxNode && maxNode->val <= root->val)
      return false;

    return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
  }
};