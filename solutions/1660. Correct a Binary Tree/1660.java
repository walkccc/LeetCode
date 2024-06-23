class Solution {
  public TreeNode correctBinaryTree(TreeNode root) {
    if (root == null)
      return null;
    if (root.right != null && seen.contains(root.right.val))
      return null;
    seen.add(root.val);
    root.right = correctBinaryTree(root.right);
    root.left = correctBinaryTree(root.left);
    return root;
  }

  private Set<Integer> seen = new HashSet<>();
}
