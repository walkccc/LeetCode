class Solution {
  public void flatten(TreeNode root) {
    flattendTail(root);
  }

  // return the tail of root after root is flattend
  private TreeNode flattendTail(TreeNode root) {
    if (root == null)
      return null;
    if (root.left == null && root.right == null)
      return root;

    TreeNode leftTail = flattendTail(root.left);
    TreeNode rightTail = flattendTail(root.right);

    if (leftTail != null) {
      leftTail.right = root.right;
      root.right = root.left;
      root.left = null;
    }

    return rightTail == null ? leftTail : rightTail;
  }
}
