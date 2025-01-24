class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (root == nullptr)
      return 0;

    long ans = 0;
    dfs(root, 0, 1, {}, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int level, long index, vector<long>&& startOfLevel,
           long& ans) {
    if (root == nullptr)
      return;
    if (startOfLevel.size() == level)
      startOfLevel.push_back(index);

    ans = max(ans, index - startOfLevel[level] + 1);
    dfs(root->left, level + 1, index * 2, std::move(startOfLevel), ans);
    dfs(root->right, level + 1, index * 2 + 1, std::move(startOfLevel), ans);
  }
};
