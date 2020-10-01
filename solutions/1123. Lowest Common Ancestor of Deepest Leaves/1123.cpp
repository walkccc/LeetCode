struct Info {
  TreeNode* lca;
  int height;
};

class Solution {
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return helper(root).lca;
  }

 private:
  Info helper(TreeNode* root) {
    if (!root) return {nullptr, 0};

    const Info l = helper(root->left);
    const Info r = helper(root->right);

    if (l.height > r.height) return {l.lca, l.height + 1};
    if (l.height < r.height) return {r.lca, r.height + 1};
    return {root, l.height + 1};
  }
};