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

    TreeNode l = lca(root.left, nodesSet);
    TreeNode r = lca(root.right, nodesSet);

    if (l != null && r != null)
      return root;
    return l == null ? r : l;
  }
}
