class Solution {
 public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    return isValidSequence(root, arr, 0);
  }

 private:
  bool isValidSequence(TreeNode* root, const vector<int>& arr, int i) {
    if (root == nullptr)
      return false;
    if (i == arr.size() - 1)
      return root->val == arr[i] && root->left == nullptr &&
             root->right == nullptr;
    return root->val == arr[i] && (isValidSequence(root->left, arr, i + 1) ||
                                   isValidSequence(root->right, arr, i + 1));
  }
};
