class BSTIterator {
  public BSTIterator(TreeNode root) {
    inorder(root);
  }

  public int next() {
    return vals.get(i++);
  }

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
