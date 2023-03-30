class Solution {
  public TreeNode reverseOddLevels(TreeNode root) {
    dfs(root.left, root.right, true);
    return root;
  }

  private void dfs(TreeNode left, TreeNode right, boolean isOddLevel) {
    if (left == null)
      return;
    if (isOddLevel) {
      final int val = left.val;
      left.val = right.val;
      right.val = val;
    }
    dfs(left.left, right.right, !isOddLevel);
    dfs(left.right, right.left, !isOddLevel);
  }
}
