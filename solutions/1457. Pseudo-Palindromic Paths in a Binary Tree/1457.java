class Solution {
  public int pseudoPalindromicPaths(TreeNode root) {
    dfs(root, 0);
    return ans;
  }

  private int ans = 0;

  private void dfs(TreeNode root, int path) {
    if (root == null)
      return;
    if (root.left == null && root.right == null) {
      path ^= 1 << root.val;
      if ((path & (path - 1)) == 0)
        ++ans;
      return;
    }

    dfs(root.left, path ^ 1 << root.val);
    dfs(root.right, path ^ 1 << root.val);
  }
}
