class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      root = q.front(), q.pop();
      if (root->right) q.push(root->right);
      if (root->left) q.push(root->left);
    }

    return root->val;
  }
};