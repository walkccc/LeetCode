class Solution {
 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string pathToStart;
    string pathToDest;

    dfs(root, startValue, pathToStart);
    dfs(root, destValue, pathToDest);

    while (!pathToStart.empty() && !pathToDest.empty() &&
           pathToStart.back() == pathToDest.back()) {
      pathToStart.pop_back();
      pathToDest.pop_back();
    }

    return string(pathToStart.length(), 'U') +
           string(rbegin(pathToDest), rend(pathToDest));
  }

 private:
  // build the string in reverse order to avoid creating new copy
  bool dfs(TreeNode* root, int val, string& path) {
    if (root->val == val)
      return true;
    if (root->left && dfs(root->left, val, path))
      path.push_back('L');
    else if (root->right && dfs(root->right, val, path))
      path.push_back('R');
    return !path.empty();
  }
};
