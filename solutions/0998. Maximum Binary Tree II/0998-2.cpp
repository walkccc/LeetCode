class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root->val < val)
      return new TreeNode(val, root, nullptr);
    TreeNode* curr = root;
    while (curr->right && curr->right->val > val)
      curr = curr->right;
    TreeNode* inserted = new TreeNode(val, curr->right, nullptr);
    curr->right = inserted;
    return root;
  }
};
