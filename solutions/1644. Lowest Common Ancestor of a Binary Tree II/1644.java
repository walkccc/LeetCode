class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    TreeNode lca = getLCA(root, p, q);
    return seenP && seenQ ? lca : null;
  }

  private boolean seenP = false;
  private boolean seenQ = false;

  private TreeNode getLCA(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null)
      return null;
    // Need to traverse the entire tree to update `seenP` and `seenQ`.
    TreeNode left = getLCA(root.left, p, q);
    TreeNode right = getLCA(root.right, p, q);
    if (root == p) {
      seenP = true;
      return root;
    }
    if (root == q) {
      seenQ = true;
      return root;
    }
    if (left != null && right != null)
      return root;
    return left == null ? right : left;
  }
}
