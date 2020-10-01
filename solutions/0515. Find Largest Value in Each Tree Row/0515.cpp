class Solution {
 public:
  vector<int> largestValues(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      int maxi = INT_MIN;
      for (int i = q.size(); i > 0; --i) {
        root = q.front(), q.pop();
        maxi = max(maxi, root->val);
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      ans.push_back(maxi);
    }

    return ans;
  }
};