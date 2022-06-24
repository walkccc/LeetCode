class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root)
      return;

    stack<TreeNode*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      if (root->right)
        stack.push(root->right);
      if (root->left)
        stack.push(root->left);
      if (!stack.empty())
        root->right = stack.top();
      root->left = nullptr;
    }
  }
};
