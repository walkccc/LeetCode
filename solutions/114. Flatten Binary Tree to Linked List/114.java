class Solution {
  public void flatten(TreeNode root) {
    if (root == null)
      return;

    flatten(root.left);
    flatten(root.right);

    TreeNode left = root.left;   // flattened left
    TreeNode right = root.right; // flattened right

    root.left = null;
    root.right = left;

    // Connect the original right subtree to the end of the new right subtree.
    TreeNode rightmost = root;
    while (rightmost.right != null)
      rightmost = rightmost.right;
    rightmost.right = right;
  }
}
