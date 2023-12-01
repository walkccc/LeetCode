class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode* newRoot = new TreeNode(v);
      newRoot->left = root;
      return newRoot;
    }

    int depth = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ++depth;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        if (depth == d - 1) {
          TreeNode* cachedLeft = node->left;
          TreeNode* cachedRight = node->right;
          node->left = new TreeNode(v);
          node->right = new TreeNode(v);
          node->left->left = cachedLeft;
          node->right->right = cachedRight;
        }
      }
      if (depth == d - 1)
        break;
    }

    return root;
  }
};
