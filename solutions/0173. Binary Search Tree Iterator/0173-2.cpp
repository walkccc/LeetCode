class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    pushLeftsUntilNull(root);
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* root = stack.top();
    stack.pop();
    pushLeftsUntilNull(root->right);
    return root->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !stack.empty();
  }

 private:
  stack<TreeNode*> stack;

  void pushLeftsUntilNull(TreeNode* root) {
    while (root) {
      stack.push(root);
      root = root->left;
    }
  }
};
