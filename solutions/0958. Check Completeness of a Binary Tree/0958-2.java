class Solution {
  public boolean isCompleteTree(TreeNode root) {
    final int nNodes = count(root);
    return isValidIndex(root, 1, nNodes);
  }

  private int count(TreeNode root) {
    if (root == null)
      return 0;
    return 1 + count(root.left) + count(root.right);
  }

  private boolean isValidIndex(TreeNode root, int i, int nNodes) {
    if (root == null)
      return true;
    if (i > nNodes)
      return false;
    return isValidIndex(root.left, i * 2, nNodes) &&
           isValidIndex(root.right, i * 2 + 1, nNodes);
  }
}
