class Solution {
 public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (root == nullptr)
      return nullptr;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    return isLeaf(root) && root->val == target ? nullptr : root;
  }

 private:
  bool isLeaf(TreeNode* root) {
    return root->left == nullptr && root->right == nullptr;
  }
};
