class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q{{root}};
    TreeNode* node = nullptr;

    while (!q.empty()) {
      node = q.front();
      q.pop();
      if (node->right)
        q.push(node->right);
      if (node->left)
        q.push(node->left);
    }

    return node->val;
  }
};
