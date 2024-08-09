class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stack;

    while (root) {
      stack.push(root);
      root = root->left;
    }

    for (int i = 0; i < k - 1; ++i) {
      root = stack.top(), stack.pop();
      root = root->right;
      while (root) {
        stack.push(root);
        root = root->left;
      }
    }

    return stack.top()->val;
  }
};
