class CBTInserter {
  public CBTInserter(TreeNode root) {
    tree.add(root);
    for (int i = 0; i < tree.size(); ++i) {
      TreeNode node = tree.get(i);
      if (node.left != null)
        tree.add(node.left);
      if (node.right != null)
        tree.add(node.right);
    }
  }

  public int insert(int v) {
    final int n = tree.size();
    TreeNode node = new TreeNode(v);
    TreeNode parent = tree.get((n - 1) / 2);
    tree.add(node);
    if (n % 2 == 1)
      parent.left = node;
    else
      parent.right = node;
    return parent.val;
  }

  public TreeNode get_root() {
    return tree.get(0);
  }

  private List<TreeNode> tree = new ArrayList<>();
}
