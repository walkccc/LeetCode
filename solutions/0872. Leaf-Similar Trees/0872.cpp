class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1;
    vector<int> leaves2;
    dfs(root1, leaves1);
    dfs(root2, leaves2);
    return leaves1 == leaves2;
  }

  void dfs(TreeNode* root, vector<int>& leaves) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr) {
      leaves.push_back(root->val);
      return;
    }

    dfs(root->left, leaves);
    dfs(root->right, leaves);
  }
};
