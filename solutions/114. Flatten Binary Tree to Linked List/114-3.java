class Solution {
  public void flatten(TreeNode root) {
    if (root == null)
      return;

    while (root != null) {
      if (root.left != null) {
        // Find the rightmost root.
        TreeNode rightmost = root.left;
        while (rightmost.right != null)
          rightmost = rightmost.right;
        // Rewire the connections.
        rightmost.right = root.right;
        root.right = root.left;
        root.left = null;
      }
      // Move on to the right side of the tree.
      root = root.right;
    }
  }
}
