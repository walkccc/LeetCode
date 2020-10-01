class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, set<pair<int, int>>> xToSortedPairs;  // {x: {y, val}}

    function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int x,
                                                  int y) {
      if (!root) return;

      xToSortedPairs[x].insert({y, root->val});
      dfs(root->left, x - 1, y + 1);
      dfs(root->right, x + 1, y + 1);
    };

    dfs(root, 0, 0);

    for (const auto& [_, items] : xToSortedPairs) {
      vector<int> vals;
      for (const auto& item : items)
        vals.push_back(item.second);
      ans.push_back(vals);
    }

    return ans;
  }
};