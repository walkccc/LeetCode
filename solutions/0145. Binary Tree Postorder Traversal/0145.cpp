class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*)> postorder = [&](TreeNode* root) {
      if (!root) return;

      postorder(root->left);
      postorder(root->right);
      ans.push_back(root->val);
    };

    postorder(root);

    return ans;
  }
};