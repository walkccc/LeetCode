class Solution {
  public void flatten(TreeNode root) {
    if (root == null)
      return;

    while (root != null) {
      if (root.left != null) {
        // find the rightmost root
        TreeNode rightmost = root.left;
        while (rightmost.right != null)
          rightmost = rightmost.right;
        // rewire the connections
        rightmost.right = root.right;
        root.right = root.left;
        root.left = null;
      }
      // move on to the right side of the tree
      root = root.right;
    }
  }
}
