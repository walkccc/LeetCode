class BSTIterator {
  public BSTIterator(TreeNode root) {
    pushLeftsUntilNull(root);
  }

  public int next() {
    TreeNode root = stack.pop();
    pushLeftsUntilNull(root.right);
    return root.val;
  }

  public boolean hasNext() {
    return !stack.isEmpty();
  }

  private Deque<TreeNode> stack = new ArrayDeque<>();

  private void pushLeftsUntilNull(TreeNode root) {
    while (root != null) {
      stack.push(root);
      root = root.left;
    }
  }
}
