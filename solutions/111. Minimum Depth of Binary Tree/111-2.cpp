class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    int ans = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
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
