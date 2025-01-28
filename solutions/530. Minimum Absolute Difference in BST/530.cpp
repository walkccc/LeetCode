class Solution {
 public:
  // Similar to 94. Binary Tree Inorder Traversal
  int getMinimumDifference(TreeNode* root) {
    int ans = INT_MAX;
    int prev = -1;
    stack<TreeNode*> stack;

    while (root != nullptr || !stack.empty()) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (prev >= 0)
        ans = min(ans, root->val - prev);
      prev = root->val;
      root = root->right;
    }

    return ans;
  }
};
