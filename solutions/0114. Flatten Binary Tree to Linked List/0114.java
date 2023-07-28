class Solution {
  public void flatten(TreeNode root) {
    if (root == null)
      return;

    flatten(root.left);
    flatten(root.right);

    TreeNode left = root.left;   // Flattened left
    TreeNode right = root.right; // Flattened right

    root.left = null;
    root.right = left;

    // Connect the original right subtree
    // To the end of new right subtree
    TreeNode rightmost = root;
    while (rightmost.right != null)
      rightmost = rightmost.right;
    rightmost.right = right;
  }
}
