class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
  }

 private:
  void postorder(TreeNode* root, vector<int>& ans) {
    if (!root)
      return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
  }
};
