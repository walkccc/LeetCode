class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    int ans = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ++ans;
      for (int i = q.size(); i > 0; --i) {
        root = q.front(), q.pop();
        if (!root->left && !root->right) return ans;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }

    throw;
  }
};