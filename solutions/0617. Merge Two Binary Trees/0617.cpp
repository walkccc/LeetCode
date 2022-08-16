class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
      return nullptr;
    const int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
    TreeNode* root = new TreeNode(val);
    root->left = mergeTrees(root1 ? root1->left : nullptr,
                            root2 ? root2->left : nullptr);
    root->right = mergeTrees(root1 ? root1->right : nullptr,
                             root2 ? root2->right : nullptr);
    return root;
  }
};
