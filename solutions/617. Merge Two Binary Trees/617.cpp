class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
      return nullptr;
    const int val = (root1 == nullptr ? 0 : root1->val) +
                    (root2 == nullptr ? 0 : root2->val);
    TreeNode* root = new TreeNode(val);
    root->left = mergeTrees(root1 == nullptr ? nullptr : root1->left,
                            root2 == nullptr ? nullptr : root2->left);
    root->right = mergeTrees(root1 == nullptr ? nullptr : root1->right,
                             root2 == nullptr ? nullptr : root2->right);
    return root;
  }
};
