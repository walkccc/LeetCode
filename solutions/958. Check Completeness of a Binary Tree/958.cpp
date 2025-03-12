class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    if (root == nullptr)
      return true;

    queue<TreeNode*> q{{root}};

    while (q.front() != nullptr) {
      TreeNode* node = q.front();
      q.pop();
      q.push(node->left);
      q.push(node->right);
    }

    while (!q.empty() && q.front() == nullptr)
      q.pop();

    return q.empty();
  }
};
