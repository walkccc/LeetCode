class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ans = getLCA(root, p, q);
    if (ans == p)  // Search q in the subtree rooted at p.
      return getLCA(p, q, q) == nullptr ? nullptr : ans;
    if (ans == q)  // Search p in the subtree rooted at q.
      return getLCA(q, p, p) == nullptr ? nullptr : ans;
    return ans;  // (ans != p && ans != q) || ans == nullptr
  }

 private:
  TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q)
      return root;
    TreeNode* left = getLCA(root->left, p, q);
    TreeNode* right = getLCA(root->right, p, q);
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }
};
