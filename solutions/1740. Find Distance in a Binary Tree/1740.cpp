class Solution {
 public:
  int findDistance(TreeNode* root, int p, int q) {
    TreeNode* lca = getLCA(root, p, q);
    return dist(lca, p) + dist(lca, q);
  }

 private:
  TreeNode* getLCA(TreeNode* root, int p, int q) {
    if (!root || root->val == p || root->val == q)
      return root;

    TreeNode* l = getLCA(root->left, p, q);
    TreeNode* r = getLCA(root->right, p, q);

    if (l && r)
      return root;
    return l ? l : r;
  }

  int dist(TreeNode* lca, int target) {
    if (!lca)
      return 10000;
    if (lca->val == target)
      return 0;
    return 1 + min(dist(lca->left, target), dist(lca->right, target));
  }
};
