class Solution {
 public:
  char getKthCharacter(RopeTreeNode* root, int k) {
    while (root->len > 0) {
      const int leftLen = root->left == nullptr
                              ? 0
                              : max(root->left->len,
                                    static_cast<int>(root->left->val.length()));
      if (leftLen >= k) {
        root = root->left;
      } else {
        root = root->right;
        k -= leftLen;
      }
    }
    return root->val[k - 1];
  }
};
