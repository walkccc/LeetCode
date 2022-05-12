class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
      return {};

    vector<vector<int>> ans;
    deque<TreeNode*> q{{root}};
    bool isLeftToRight = true;

    while (!q.empty()) {
      vector<int> currLevel;
      for (int sz = q.size(); sz > 0; --sz)
        if (isLeftToRight) {
          TreeNode* node = q.front();
          q.pop_front();
          currLevel.push_back(node->val);
          if (node->left)
            q.push_back(node->left);
          if (node->right)
            q.push_back(node->right);
        } else {
          TreeNode* node = q.back();
          q.pop_back();
          currLevel.push_back(node->val);
          if (node->right)
            q.push_front(node->right);
          if (node->left)
            q.push_front(node->left);
        }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};
