class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    // levelSums[i] := sum of level (i + 1) (1-indexed)
    vector<int> levelSums;
    dfs(root, 0, levelSums);
    return 1 + max_element(begin(levelSums), end(levelSums)) - begin(levelSums);
  }

 private:
  void dfs(TreeNode* root, int level, vector<int>& levelSums) {
    if (root == nullptr)
      return;
    if (levelSums.size() == level)
      levelSums.push_back(0);
    levelSums[level] += root->val;
    dfs(root->left, level + 1, levelSums);
    dfs(root->right, level + 1, levelSums);
  }
};
