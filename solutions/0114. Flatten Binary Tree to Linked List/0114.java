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

    // connect the original right subtree
    // to the end of new right subtree
    TreeNode rightmost = root;
    while (rightmost.right != null)
      rightmost = rightmost.right;
    rightmost.right = right;
  }
}
