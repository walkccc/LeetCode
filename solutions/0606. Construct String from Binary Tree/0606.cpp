class Solution {
 public:
  string tree2str(TreeNode* t) {
    string ans;

    function<void(TreeNode*)> dfs = [&](TreeNode* root) {
      ans += to_string(root->val);
      if (!root->left && !root->right) return;

      // left node
      ans += "(";
      if (root->left) dfs(root->left);
      ans += ")";

      // right node
      if (root->right) {
        ans += "(";
        dfs(root->right);
        ans += ")";
      }
    };

    if (!t) return "";

    dfs(t);

    return ans;
  }
};