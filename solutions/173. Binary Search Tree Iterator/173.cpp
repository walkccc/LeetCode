class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    inorder(root);
  }

  int next() {
    return vals[i++];
  }

  bool hasNext() {
    return i < vals.size();
  }

 private:
  int i = 0;
  vector<int> vals;

  void inorder(TreeNode* root) {
    if (root == nullptr)
      return;
    inorder(root->left);
    vals.push_back(root->val);
    inorder(root->right);
  }
};
