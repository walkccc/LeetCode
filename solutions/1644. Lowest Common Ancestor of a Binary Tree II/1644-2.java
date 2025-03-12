class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    TreeNode ans = getLCA(root, p, q);
    if (ans == p) // Search q in the subtree rooted at p.
      return getLCA(p, q, q) == null ? null : ans;
    if (ans == q) // Search p in the subtree rooted at q.
      return getLCA(q, p, p) == null ? null : ans;
    return ans; // (ans != p && ans != q) || ans == null
  }

  private TreeNode getLCA(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || root == p || root == q)
      return root;
    TreeNode left = getLCA(root.left, p, q);
    TreeNode right = getLCA(root.right, p, q);
    if (left != null && right != null)
      return root;
    return left == null ? right : left;
  }
}
