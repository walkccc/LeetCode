class Solution {
 public:
  // Similar to 1161. Maximum Level Sum of a Binary Tree
  int minimumLevel(TreeNode* root) {
    int ans = 0;
    long minLevelSum = LONG_MAX;
    queue<TreeNode*> q{{root}};

    for (int level = 1; !q.empty(); ++level) {
      long levelSum = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* node = q.front();
        q.pop();
        levelSum += node->val;
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
      if (levelSum < minLevelSum) {
        minLevelSum = levelSum;
        ans = level;
      }
    }

    return ans;
  }
};
