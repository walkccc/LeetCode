class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stack;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      ans.push_back(root->val);
      root = root->right;
    }

    return ans;
  }
};
