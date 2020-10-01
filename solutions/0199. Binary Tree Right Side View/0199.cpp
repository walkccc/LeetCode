class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      const int size = q.size();
      for (int i = 0; i < size; ++i) {
        root = q.front(), q.pop();
        if (i == size - 1) ans.push_back(root->val);
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }

    return ans;
  }
};