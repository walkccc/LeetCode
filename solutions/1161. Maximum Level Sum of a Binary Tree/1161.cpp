class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    int ans = 1;
    int maxLevelSum = INT_MIN;
    queue<TreeNode*> q{{root}};

    for (int level = 1; !q.empty(); ++level) {
      int levelSum = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        levelSum += node->val;
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
      if (maxLevelSum < levelSum) {
        maxLevelSum = levelSum;
        ans = level;
      }
    }

    return ans;
  }
};
