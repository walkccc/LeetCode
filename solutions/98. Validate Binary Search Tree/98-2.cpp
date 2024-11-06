class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode* pred = nullptr;

    while (root != nullptr || !stack.empty()) {
      while (root != nullptr) {
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
