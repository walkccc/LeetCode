class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    long ans = 0;
    vector<long> startOfLevel;

    function<void(TreeNode*, int, long)> dfs = [&](TreeNode* root, int level,
                                                   long index) {
      if (!root) return;
      if (startOfLevel.size() == level)
        startOfLevel.push_back(index);
      ans = max(ans, index - startOfLevel[level] + 1);
      dfs(root->left, level + 1, index * 2);
      dfs(root->right, level + 1, index * 2 + 1);
    };

    dfs(root, 0, 1);

    return ans;
  }
};