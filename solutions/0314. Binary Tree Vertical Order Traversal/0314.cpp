class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return {};

    vector<int> range(2);
    getRange(root, range, 0);  // get the leftmost and rightmost column index

    vector<vector<int>> ans(range[1] - range[0] + 1);
    queue<pair<TreeNode*, int>> q{{{root, -range[0]}}};  // {TreeNode, colIndex}

    while (!q.empty()) {
      const auto [node, colIndex] = q.front(); q.pop();
      ans[colIndex].push_back(node->val);
      if (node->left) q.push({node->left, colIndex - 1});
      if (node->right) q.push({node->right, colIndex + 1});
    }

    return ans;
  }

 private:
  void getRange(TreeNode* root, vector<int>& range, int col) {
    if (!root) return;

    range[0] = min(range[0], col);
    range[1] = max(range[1], col);

    getRange(root->left, range, col - 1);
    getRange(root->right, range, col + 1);
  }
};