class Solution {
  public TreeNode removeLeafNodes(TreeNode root, int target) {
    if (root == null)
      return null;
    root.left = removeLeafNodes(root.left, target);
    root.right = removeLeafNodes(root.right, target);
    return isLeaf(root) && root.val == target ? null : root;
  }

  private boolean isLeaf(TreeNode root) {
    return root.left == null && root.right == null;
  }
}
