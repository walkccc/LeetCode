class Solution {
  public int heightOfTree(TreeNode root) {
    if (root == null)
      return 0;
    // a leaf node
    if (root.left != null && root.left.right == root)
      return 0;
    return 1 + Math.max(heightOfTree(root.left), heightOfTree(root.right));
  }
}
