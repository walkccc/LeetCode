class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*)> preorder = [&](TreeNode* root) {
      if (!root) return;

      ans.push_back(root->val);
      preorder(root->left);
      preorder(root->right);
    };

    preorder(root);

    return ans;
  }
};