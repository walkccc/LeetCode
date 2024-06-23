class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    if (root == nullptr)
      return false;

    queue<TreeNode*> queue{{root}};

    while (!queue.empty()) {
      bool isFindX = false;
      bool isFindY = false;
      for (int i = queue.size(); i > 0; --i) {
        root = queue.front(), queue.pop();
        if (root->val == x)
          isFindX = true;
        else if (root->val == y)
          isFindY = true;
        else if (root->left && root->right) {
          if (root->left->val == x && root->right->val == y)
            return false;
          if (root->left->val == y && root->right->val == x)
            return false;
        }
        if (root->left)
          queue.push(root->left);
        if (root->right)
          queue.push(root->right);
      }
      if (isFindX && isFindY)
        return true;
      else if (isFindX || isFindY)
        return false;
    }

    return false;
  }
};
