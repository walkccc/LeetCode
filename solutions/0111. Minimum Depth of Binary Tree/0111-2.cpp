class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;

    int ans = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ++ans;
      for (int size = q.size(); size > 0; --size) {
        TreeNode* node = q.front();
        q.pop();
        if (!node->left && !node->right)
          return ans;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    throw;
  }
};
