class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* pred = nullptr;
    TreeNode* x = nullptr;  // 1st wrong node
    TreeNode* y = nullptr;  // 2nd wrong node

    stack<TreeNode*> stack;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (pred && root->val < pred->val) {
        y = root;
        if (!x)
          x = pred;
      }
      pred = root;
      root = root->right;
    }

    swap(x, y);
  }

  void swap(TreeNode* x, TreeNode* y) {
    const int temp = x->val;
    x->val = y->val;
    y->val = temp;
  }
};
