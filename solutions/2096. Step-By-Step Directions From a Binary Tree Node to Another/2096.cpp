class Solution {
 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string path;
    string pathToStart;
    string pathToDest;
    // Only this subtree matters.
    dfs(lca(root, startValue, destValue), startValue, destValue, path,
        pathToStart, pathToDest);
    return string(pathToStart.length(), 'U') + pathToDest;
  }

 private:
  TreeNode* lca(TreeNode* root, int p, int q) {
    if (root == nullptr || root->val == p || root->val == q)
      return root;
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }

  void dfs(TreeNode* root, int p, int q, string& path, string& pathToStart,
           string& pathToDest) {
    if (root == nullptr)
      return;
    if (root->val == p)
      pathToStart = path;
    if (root->val == q)
      pathToDest = path;
    path.push_back('L');
    dfs(root->left, p, q, path, pathToStart, pathToDest);
    path.pop_back();
    path.push_back('R');
    dfs(root->right, p, q, path, pathToStart, pathToDest);
    path.pop_back();
  }
};
