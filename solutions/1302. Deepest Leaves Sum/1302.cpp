class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      ans = 0;
      for (int sz = q.size(); sz > 0; --sz) {
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
