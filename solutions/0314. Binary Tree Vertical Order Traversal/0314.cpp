class Solution {
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root)
      return {};

    vector<int> range(2);
    getRange(root, range, 0);  // get the leftmost and rightmost x index

    vector<vector<int>> ans(range[1] - range[0] + 1);
    queue<pair<TreeNode*, int>> q{{{root, -range[0]}}};  // (TreeNode, x)

    while (!q.empty()) {
      const auto [node, x] = q.front();
      q.pop();
      ans[x].push_back(node->val);
      if (node->left)
        q.emplace(node->left, x - 1);
      if (node->right)
        q.emplace(node->right, x + 1);
    }

    return ans;
  }

 private:
  void getRange(TreeNode* root, vector<int>& range, int x) {
    if (!root)
      return;

    range[0] = min(range[0], x);
    range[1] = max(range[1], x);

    getRange(root->left, range, x - 1);
    getRange(root->right, range, x + 1);
  }
};
