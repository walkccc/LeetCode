class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    vector<int> levelSums;
    dfs(root, 0, levelSums);
    return replace(root, 0, new TreeNode(0), levelSums);
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

  TreeNode* replace(TreeNode* root, int level, TreeNode* curr,
                    const vector<int>& levelSums) {
    const int nextLevel = level + 1;
    const int nextLevelCousinsSum =
        nextLevel >= levelSums.size()
            ? 0
            : levelSums[nextLevel] -
                  (root->left == nullptr ? 0 : root->left->val) -
                  (root->right == nullptr ? 0 : root->right->val);
    if (root->left != nullptr) {
      curr->left = new TreeNode(nextLevelCousinsSum);
      replace(root->left, level + 1, curr->left, levelSums);
    }
    if (root->right != nullptr) {
      curr->right = new TreeNode(nextLevelCousinsSum);
      replace(root->right, level + 1, curr->right, levelSums);
    }
    return curr;
  }
};
