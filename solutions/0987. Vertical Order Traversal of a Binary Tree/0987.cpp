class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, multiset<pair<int, int>>> xToSortedPairs;  // {x: {(-y, val)}}

    dfs(root, 0, 0, xToSortedPairs);

    for (const auto& [_, pairs] : xToSortedPairs) {
      vector<int> vals;
      for (const pair<int, int>& pair : pairs)
        vals.push_back(pair.second);
      ans.push_back(vals);
    }

    return ans;
  }

 private:
  void dfs(TreeNode* root, int x, int y,
           map<int, multiset<pair<int, int>>>& xToSortedPairs) {
    if (root == nullptr)
      return;

    xToSortedPairs[x].emplace(y, root->val);
    dfs(root->left, x - 1, y + 1, xToSortedPairs);
    dfs(root->right, x + 1, y + 1, xToSortedPairs);
  }
};
