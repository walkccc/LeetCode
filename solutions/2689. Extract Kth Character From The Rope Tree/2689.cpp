class Solution {
 public:
  char getKthCharacter(RopeTreeNode* root, int k) {
    if (root->len == 0)
      return root->val[k - 1];
    const int leftLen =
        root->left == nullptr
            ? 0
            : max(root->left->len, static_cast<int>(root->left->val.length()));
    return leftLen >= k ? getKthCharacter(root->left, k)
                        : getKthCharacter(root->right, k - leftLen);
  }
};
