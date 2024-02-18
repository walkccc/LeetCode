class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    // flattened left
    TreeNode* const right = root->right;  // flattened right

    root->left = nullptr;
    root->right = left;

    // Connect the original right subtree to the end of the new right subtree.
    TreeNode* rightmost = root;
    while (rightmost->right)
      rightmost = rightmost->right;
    rightmost->right = right;
  }
};
