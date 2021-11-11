class BSTIterator {
  public BSTIterator(TreeNode root) {
    pushLeftsUntilNull(root);
  }

  /** @return the next smallest number */
  public int next() {
    TreeNode root = stack.pop();
    pushLeftsUntilNull(root.right);
    return root.val;
  }

  /** @return whether we have a next smallest number */
  public boolean hasNext() {
    return !stack.isEmpty();
  }

  private Stack<TreeNode> stack = new Stack<>();

  private void pushLeftsUntilNull(TreeNode root) {
    while (root != null) {
      stack.push(root);
      root = root.left;
    }
  }
}
