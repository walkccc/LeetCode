class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    inorder(root);
  }

  /** @return the next smallest number */
  int next() {
    return vals[i++];
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return i < vals.size();
  }

 private:
  int i = 0;
  vector<int> vals;

  void inorder(TreeNode* root) {
    if (!root)
      return;

    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
  }
};
