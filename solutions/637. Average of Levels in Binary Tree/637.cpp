class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      long sum = 0;
      const int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(sum / (double)size);
    }

    return ans;
  }
};
