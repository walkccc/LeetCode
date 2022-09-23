class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root)
      return {};

    vector<vector<int>> ans;
    queue<TreeNode*> q{{root}};
    bool isLeftToRight = true;

    while (!q.empty()) {
      const int size = q.size();
      vector<int> currLevel(size);
      for (int i = 0; i < size; ++i) {
        TreeNode* node = q.front();
        q.pop();
        const int index = isLeftToRight ? i : size - i - 1;
        currLevel[index] = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      ans.push_back(node);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};
