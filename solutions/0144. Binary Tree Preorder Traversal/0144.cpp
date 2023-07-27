class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }

 private:
  void preorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
      return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
  }
};
