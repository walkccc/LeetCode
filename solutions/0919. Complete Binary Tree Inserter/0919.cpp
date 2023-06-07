class CBTInserter {
 public:
  CBTInserter(TreeNode* root) {
    tree.push_back(root);
    for (int i = 0; i < tree.size(); ++i) {
      TreeNode* node = tree[i];
      if (node->left)
        tree.push_back(node->left);
      if (node->right)
        tree.push_back(node->right);
    }
  }

  int insert(int v) {
    const int n = tree.size();
    tree.push_back(new TreeNode(v));
    auto& parent = tree[(n - 1) / 2];
    if (n & 1)
      parent->left = tree.back();
    else
      parent->right = tree.back();
    return parent->val;
  }

  TreeNode* get_root() {
    return tree[0];
  }

 private:
  vector<TreeNode*> tree;
};
