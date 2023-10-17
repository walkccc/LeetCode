class Solution {
 public:
  TreeNode* correctBinaryTree(TreeNode* root) {
    if (root == nullptr)
      return nullptr;
    if (root->right != nullptr && seen.count(root->right->val))
      return nullptr;
    seen.insert(root->val);
    root->right = correctBinaryTree(root->right);
    root->left = correctBinaryTree(root->left);
    return root;
  }

 private:
  unordered_set<int> seen;
};
