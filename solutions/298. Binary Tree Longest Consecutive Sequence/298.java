class Solution {
  public int longestConsecutive(TreeNode root) {
    if (root == null)
      return 0;
    return dfs(root, -1, 0, 1);
  }

  private int dfs(TreeNode root, int target, int length, int max) {
    if (root == null)
      return max;
    if (root.val == target)
      max = Math.max(max, ++length);
    else
      length = 1;
    return Math.max(dfs(root.left, root.val + 1, length, max),
                    dfs(root.right, root.val + 1, length, max));
  }
}
