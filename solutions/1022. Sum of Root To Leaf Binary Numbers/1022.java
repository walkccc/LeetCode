class Solution {
  public int sumRootToLeaf(TreeNode root) {
    dfs(root, 0);
    return ans;
  }

  private int ans = 0;

  private void dfs(TreeNode root, int val) {
    if (root == null)
      return;
    val = val * 2 + root.val;
    if (root.left == null && root.right == null)
      ans += val;
    dfs(root.left, val);
    dfs(root.right, val);
  }
}
