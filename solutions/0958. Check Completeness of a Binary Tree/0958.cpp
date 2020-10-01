class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    if (!root) return true;

    queue<TreeNode*> q{{root}};

    while (q.front() != nullptr) {
      root = q.front(), q.pop();
      q.push(root->left);
      q.push(root->right);
    }

    while (!q.empty() && q.front() == nullptr)
      q.pop();

    return q.empty();
  }
};