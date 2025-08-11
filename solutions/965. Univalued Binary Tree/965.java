class Solution {
  public boolean isUnivalTree(TreeNode root) {
    if (root == null)
      return true;
    if (root.left != null && root.left.val != root.val)
      return false;
    if (root.right != null && root.right.val != root.val)
      return false;
    return isUnivalTree(root.left) && isUnivalTree(root.right);
  }
}
