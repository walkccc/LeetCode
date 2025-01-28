class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    unordered_set<TreeNode*> nodesSet{nodes.begin(), nodes.end()};
    return lca(root, nodesSet);
  }

 private:
  TreeNode* lca(TreeNode* root, unordered_set<TreeNode*>& nodesSet) {
    if (root == nullptr)
      return nullptr;
    if (nodesSet.contains(root))
      return root;
    TreeNode* left = lca(root->left, nodesSet);
    TreeNode* right = lca(root->right, nodesSet);
    if (left != nullptr && right != nullptr)
      return root;
    return left == nullptr ? right : left;
  }
};
