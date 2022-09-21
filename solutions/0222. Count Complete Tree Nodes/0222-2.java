class Solution {
  public int countNodes(TreeNode root) {
    if (root == null)
      return 0;

    TreeNode l = root;
    TreeNode r = root;
    int heightL = 0;
    int heightR = 0;

    while (l != null) {
      ++heightL;
      l = l.left;
    }

    while (r != null) {
      ++heightR;
      r = r.right;
    }

    if (heightL == heightR) // root is a complete tree
      return (int) Math.pow(2, heightL) - 1;
    return 1 + countNodes(root.left) + countNodes(root.right);
  }
}
