class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    deque<TreeNode*> q{{root}};
    bool isLeftToRight = true;

    while (!q.empty()) {
      vector<int> currLevel;
      for (int i = q.size(); i > 0; --i)
        if (isLeftToRight) {
          root = q.front(), q.pop_front();
          currLevel.push_back(root->val);
          if (root->left) q.push_back(root->left);
          if (root->right) q.push_back(root->right);
        } else {
          root = q.back(), q.pop_back();
          currLevel.push_back(root->val);
          if (root->right) q.push_front(root->right);
          if (root->left) q.push_front(root->left);
        }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};