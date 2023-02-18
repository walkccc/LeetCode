class Solution {
  public int maxPathSum(TreeNode root) {
    maxPathSumDownFrom(root);
    return ans;
  }

  private int ans = Integer.MIN_VALUE;

  // root->val + 0/1 of its subtrees
  private int maxPathSumDownFrom(TreeNode root) {
    if (root == null)
      return 0;

    final int l = Math.max(maxPathSumDownFrom(root.left), 0);
    final int r = Math.max(maxPathSumDownFrom(root.right), 0);
    ans = Math.max(ans, root.val + l + r);
    return root.val + Math.max(l, r);
  }
}
