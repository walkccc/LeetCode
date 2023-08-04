class Solution {
 public:
  int goodNodes(TreeNode* root, int maxi = INT_MIN) {
    if (root == nullptr)
      return 0;

    const int newMax = max(maxi, root->val);
    return (root->val >= maxi) +            //
           goodNodes(root->left, newMax) +  //
           goodNodes(root->right, newMax);
  }
};
