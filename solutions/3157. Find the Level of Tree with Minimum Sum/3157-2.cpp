class Solution {
 public:
  // Similar to 1161. Maximum Level Sum of a Binary Tree
  int minimumLevel(TreeNode* root) {
    // levelSums[i] := the sum of level (i + 1) (1-indexed)
    vector<long> levelSums;
    dfs(root, 0, levelSums);
    return 1 + ranges::min_element(levelSums) - levelSums.begin();
  }

 private:
  void dfs(TreeNode* root, int level, vector<long>& levelSums) {
    if (root == nullptr)
      return;
    if (levelSums.size() == level)
      levelSums.push_back(0);
    levelSums[level] += root->val;
    dfs(root->left, level + 1, levelSums);
    dfs(root->right, level + 1, levelSums);
  }
};
