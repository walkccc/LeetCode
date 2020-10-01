class BSTIterator {
  public BSTIterator(TreeNode root) {
    while (root != null) {
      stack.push(root);
      root = root.left;
    }
  }

  public int next() {
    TreeNode node = stack.pop();
    final int ans = node.val;

    node = node.right;
    while (node != null) {
      stack.push(node);
      node = node.left;
    }

    return ans;
  }

  public boolean hasNext() {
    return !stack.isEmpty();
  }

  private Stack<TreeNode> stack = new Stack<>();
}
