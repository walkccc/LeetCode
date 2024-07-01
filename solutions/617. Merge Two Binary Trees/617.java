class Solution {
  public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
    if (root1 == null && root2 == null)
      return null;
    final int val = (root1 == null ? 0 : root1.val) + (root2 == null ? 0 : root2.val);
    TreeNode root = new TreeNode(val);
    root.left = mergeTrees(root1 == null ? null : root1.left, root2 == null ? null : root2.left);
    root.right = mergeTrees(root1 == null ? null : root1.right, root2 == null ? null : root2.right);
    return root;
  }
}
