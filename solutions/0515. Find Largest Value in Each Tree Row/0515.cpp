class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    if (!root)
      return {};

    vector<int> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      int maxi = INT_MIN;
      for (int size = q.size(); size > 0; --size) {
        TreeNode* node = q.front();
        q.pop();
        maxi = max(maxi, node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(maxi);
    }

    return ans;
  }
};
