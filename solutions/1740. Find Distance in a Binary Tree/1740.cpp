class Solution {
 public:
  int findDistance(TreeNode* root, int p, int q) {
    TreeNode* lca = getLCA(root, p, q);
    return dist(lca, p) + dist(lca, q);
  }

 private:
  TreeNode* getLCA(TreeNode* root, int p, int q) {
    if (root == nullptr || root->val == p || root->val == q)
      return root;
    TreeNode* left = getLCA(root->left, p, q);
    TreeNode* right = getLCA(root->right, p, q);
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }

  int dist(TreeNode* lca, int target) {
    if (lca == nullptr)
      return 10000;
    if (lca->val == target)
      return 0;
    return 1 + min(dist(lca->left, target), dist(lca->right, target));
  }
};
