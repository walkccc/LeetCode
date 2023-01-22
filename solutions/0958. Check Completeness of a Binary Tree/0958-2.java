class Solution {
  public boolean isCompleteTree(TreeNode root) {
    final int count = getCount(root);
    return validIndex(root, 1, count);
  }

  private int getCount(TreeNode root) {
    if (root == null)
      return 0;
    return 1 + getCount(root.left) + getCount(root.right);
  }

  // Make sure no index is > the # of nodes
  private boolean validIndex(TreeNode root, int index, int count) {
    if (root == null)
      return true;
    if (index > count)
      return false;
    return validIndex(root.left, index * 2, count) && validIndex(root.right, index * 2 + 1, count);
  }
}
