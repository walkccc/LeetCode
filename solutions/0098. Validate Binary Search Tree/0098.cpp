class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, nullptr, nullptr);
  }

 private:
  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root)
      return true;
    if (minNode && root->val <= minNode->val)
      return false;
    if (maxNode && root->val >= maxNode->val)
      return false;

    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
  }
};
