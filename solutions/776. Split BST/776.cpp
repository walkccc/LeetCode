class Solution {
 public:
  vector<TreeNode*> splitBST(TreeNode* root, int target) {
    if (root == nullptr)
      return {nullptr, nullptr};
    if (root->val > target) {
      const vector<TreeNode*> res = splitBST(root->left, target);
      root->left = res[1];
      return {res[0], root};
    } else {  // root->val <= target
      const vector<TreeNode*> res = splitBST(root->right, target);
      root->right = res[0];
      return {root, res[1]};
    }
  }
};
