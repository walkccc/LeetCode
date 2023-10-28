class Solution {
 public:
  void flatten(TreeNode* root) {
    if (root == nullptr)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* const left = root->left;    // Flattened left
    TreeNode* const right = root->right;  // Flattened right

    root->left = nullptr;
    root->right = left;

    // Connect the original right subtree
    // To the end of new right subtree
    TreeNode* rightmost = root;
    while (rightmost->right)
      rightmost = rightmost->right;
    rightmost->right = right;
  }
};
