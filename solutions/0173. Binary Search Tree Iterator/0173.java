class BSTIterator {
  public BSTIterator(TreeNode root) {
    inorder(root);
  }

  /** @return the next smallest number */
  public int next() {
    return vals.get(i++);
  }

  /** @return whether we have a next smallest number */
  public boolean hasNext() {
    return i < vals.size();
  }

  private int i = 0;
  private List<Integer> vals = new ArrayList<>();

  private void inorder(TreeNode root) {
    if (root == null)
      return;

    inorder(root.left);
    vals.add(root.val);
    inorder(root.right);
  }
}
