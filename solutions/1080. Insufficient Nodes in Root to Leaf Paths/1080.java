class Solution {
  public TreeNode sufficientSubset(TreeNode root, int limit) {
    if (root == null)
      return null;
    if (root.left == null && root.right == null)
      return root.val < limit ? null : root;

    root.left = sufficientSubset(root.left, limit - root.val);
    root.right = sufficientSubset(root.right, limit - root.val);

    // both children are null
    return root.left == root.right ? null : root;
  }
}
