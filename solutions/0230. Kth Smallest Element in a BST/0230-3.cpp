class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> nums;

    function<void(TreeNode*)> inorder = [&](TreeNode* root) {
      if (!root) return;

      inorder(root->left);
      nums.push_back(root->val);
      inorder(root->right);
    };

    inorder(root);

    return nums[k - 1];
  }
};