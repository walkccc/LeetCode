class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    swap(x, y);
  }

 private:
  TreeNode* pred = nullptr;
  TreeNode* x = nullptr;  // 1st wrong node
  TreeNode* y = nullptr;  // 2nd wrond node

  void inorder(TreeNode* root) {
    if (!root)
      return;

    inorder(root->left);

    if (pred && root->val < pred->val) {
      y = root;
      if (!x)
        x = pred;
      else
        return;
    }
    pred = root;

    inorder(root->right);
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};
