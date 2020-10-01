class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    const int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }

 private:
  TreeNode* pred = new TreeNode(INT_MIN);
  TreeNode* first;
  TreeNode* second;

  void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (!first && pred->val > root->val) first = pred;
    if (first && pred->val > root->val) second = root;
    pred = root;

    inorder(root->right);
  }
};