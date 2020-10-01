class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int i = q.size(); i > 0; --i) {
        root = q.front(), q.pop();
        currLevel.push_back(root->val);
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      ans.push_back(currLevel);
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};