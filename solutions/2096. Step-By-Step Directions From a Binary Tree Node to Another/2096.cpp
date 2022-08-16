class Solution {
 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string path;
    string pathToStart;
    string pathToDest;
    // only this subtree matters
    dfs(lca(root, startValue, destValue), startValue, destValue, path,
        pathToStart, pathToDest);
    return string(pathToStart.length(), 'U') + pathToDest;
  }

 private:
  TreeNode* lca(TreeNode* root, int p, int q) {
    if (!root || root->val == p || root->val == q)
      return root;
    TreeNode* l = lca(root->left, p, q);
    TreeNode* r = lca(root->right, p, q);
    if (l && r)
      return root;
    return l ? l : r;
  }

  void dfs(TreeNode* root, int p, int q, string& path, string& pathToStart,
           string& pathToDest) {
    if (!root)
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
