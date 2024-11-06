class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    queue<TreeNode*> q{{root}};

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left == nullptr && node->right == nullptr)
          return step;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

    throw;
  }
};
