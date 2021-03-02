class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2)
      return nullptr;

    const int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
    TreeNode* root = new TreeNode(val);
    root->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    root->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
    return root;
  }
};
