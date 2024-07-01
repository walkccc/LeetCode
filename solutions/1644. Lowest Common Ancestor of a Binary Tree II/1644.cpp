class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    bool seenP = false;
    bool seenQ = false;
    TreeNode* lca = getLCA(root, p, q, seenP, seenQ);
    return seenP && seenQ ? lca : nullptr;
  }

 private:
  TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q, bool& seenP,
                   bool& seenQ) {
    if (root == nullptr)
      return nullptr;
    // Need to traverse the entire tree to update `seenP` and `seenQ`.
    TreeNode* left = getLCA(root->left, p, q, seenP, seenQ);
    TreeNode* right = getLCA(root->right, p, q, seenP, seenQ);
    if (root == p) {
      seenP = true;
      return root;
    }
    if (root == q) {
      seenQ = true;
      return root;
    }
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }
};
