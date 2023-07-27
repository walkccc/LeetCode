class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode* pred = nullptr;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (pred && pred->val >= root->val)
        return false;
      pred = root;
      root = root->right;
    }

    return true;
  }
};
