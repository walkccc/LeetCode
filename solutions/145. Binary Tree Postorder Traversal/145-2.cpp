class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr)
      return {};

    vector<int> ans;
    stack<TreeNode*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      ans.push_back(root->val);
      if (root->left)
        stack.push(root->left);
      if (root->right)
        stack.push(root->right);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
