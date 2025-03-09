class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nums;
    inorder(root, nums);
    return build(nums, 0, nums.size() - 1);
  }

 private:
  void inorder(TreeNode* root, vector<int>& nums) {
    if (root == nullptr)
      return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  // Same as 108. Convert Sorted Array to Binary Search Tree
  TreeNode* build(const vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    const int m = (l + r) / 2;
    return new TreeNode(nums[m], build(nums, l, m - 1), build(nums, m + 1, r));
  }
};
