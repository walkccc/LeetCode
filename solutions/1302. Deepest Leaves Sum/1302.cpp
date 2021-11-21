class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ans = 0;
      for (int size = q.size(); size > 0; --size) {
        TreeNode* node = q.front();
        q.pop();
        ans += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return ans;
  }
};
