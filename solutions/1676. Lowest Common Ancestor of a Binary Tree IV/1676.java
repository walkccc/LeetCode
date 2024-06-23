class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
    Set<TreeNode> nodesSet = new HashSet<>(Arrays.asList(nodes));
    return lca(root, nodesSet);
  }

  private TreeNode lca(TreeNode root, Set<TreeNode> nodesSet) {
    if (root == null)
      return null;
    if (nodesSet.contains(root))
      return root;
    TreeNode left = lca(root.left, nodesSet);
    TreeNode right = lca(root.right, nodesSet);
    if (left != null && right != null)
      return root;
    return left == null ? right : left;
  }
}
