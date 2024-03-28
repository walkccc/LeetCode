class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    pushLeftsUntilNull(root);
  }

  int next() {
    TreeNode* root = stack.top();
    stack.pop();
    pushLeftsUntilNull(root->right);
    return root->val;
  }

  bool hasNext() {
    return !stack.empty();
  }

 private:
  stack<TreeNode*> stack;

  void pushLeftsUntilNull(TreeNode* root) {
    while (root != nullptr) {
      stack.push(root);
      root = root->left;
    }
  }
};
