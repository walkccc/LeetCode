class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    // very similar to 94. Binary Tree Inorder Traversal
    int ans = INT_MAX;
    int prev = -1;
    stack<TreeNode*> stack;

    while (root || !stack.empty()) {
      while (root) {
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
