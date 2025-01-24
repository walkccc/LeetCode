class Solution {
 public:
  int goodNodes(TreeNode* root, int mx = INT_MIN) {
    if (root == nullptr)
      return 0;
    const int newMax = max(mx, root->val);
    return (root->val >= mx) +              //
           goodNodes(root->left, newMax) +  //
           goodNodes(root->right, newMax);
  }
};
