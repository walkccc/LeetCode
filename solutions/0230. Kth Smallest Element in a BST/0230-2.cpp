class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    int rank = 0;
    traverse(root, k, rank, ans);
    return ans;
  }

 private:
  void traverse(TreeNode* root, int k, int& rank, int& ans) {
    if (!root)
      return;

    traverse(root->left, k, rank, ans);
    if (++rank == k) {
      ans = root->val;
      return;
    }
    traverse(root->right, k, rank, ans);
  }
};
